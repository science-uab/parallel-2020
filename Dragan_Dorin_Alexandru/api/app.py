from flask import Flask
from worker import celery
import celery.states as states
import csv
import time

app = Flask(__name__)

def chunker_list(seq, size):
    return (seq[i::size] for i in range(size))

@app.route('/correct_addresses/<int:number_of_tasks>')
def correct_addresses(number_of_tasks: int) -> str:
    dataset = ["Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catel", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", "Catels", ]
    dataset = list(chunker_list(dataset, number_of_tasks))
    celery.send_task('tasks.correct_addresses', args=[number_of_tasks, dataset], kwargs={})
    return str(number_of_tasks) + " tasks started !"

@app.route('/check/<string:task_id>')
def check_task(task_id: str) -> str:
    res = celery.AsyncResult(task_id)
    if res.state == states.PENDING:
        return res.state
    else:
        return str(res.result)
