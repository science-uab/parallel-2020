# Nume proiect :
> Paralelized data process
# Autor : 
> Dragan Dorin Alexandru
# Descriere : 
> Proiectul ia datele dintr-o lista, chunk-uieste lista in functie de numarul de workeri si trimite fiecare chunk unui worker.

> Pe langa workerii de procesare, mai exista un worker care practic monitorizeaza statusul celorlati workeri si preia rezultatele odata ce workerii si-au terminat treaba.
# Tehnologii folosite:
> Python - Celery, Flower, Flask
> Redis
# Rulare proiect : 
> docker-compose up --scale worker={numar_de_workeri} --no-recreate

