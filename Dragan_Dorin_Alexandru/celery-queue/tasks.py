import os
import time
from celery import Celery, result

CELERY_BROKER_URL = os.environ.get('CELERY_BROKER_URL', 'redis://localhost:6379'),
CELERY_RESULT_BACKEND = os.environ.get('CELERY_RESULT_BACKEND', 'redis://localhost:6379')

celery = Celery('tasks', broker=CELERY_BROKER_URL, backend=CELERY_RESULT_BACKEND)

@celery.task(name='tasks.correct_address')
def correct_address(dataset, worker_sleep_time):
    time.sleep(worker_sleep_time)
    
    return "AM PRIMIT CHUNK-UL URMATOR: " + str(dataset)

@celery.task(name='tasks.correct_addresses')
def correct_addresses(number_of_workers, dataset):
    tasks = []
    for i in range(0, number_of_workers):
        tasks.append(correct_address.delay(dataset[i], i+1).id)
    check_task_completion.delay([], tasks)

@celery.task(name='tasks.check_task_completion')
def check_task_completion(results, task_ids) -> []:
    completed_tasks = []
    tasks = []
    
    for task_id in task_ids:
        tasks.append(celery.AsyncResult(task_id))
    
    for task in tasks:
        if task.ready():
            completed_tasks.append(task.id)
            with result.allow_join_result():
                results.append(task.get())

    task_ids = list(set(task_ids) - set(completed_tasks))

    if len(tasks) > 0:
        time.sleep(1)
        check_task_completion.delay(results, task_ids)
    else:
        return results