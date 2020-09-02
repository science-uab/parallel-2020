# CRAWLER WEB RECURSIV PARALELIZAT

## Popa Andrei

## Descriere 
Proiectul consta in parcurgerea recursiva a tuturor link-urilor gasite intr-o pagina web, precum si a link-urilor gastie in fiecare sublink.

## Tehnologii folosite
Limbajul de programare: Python3
Biblioteci: 
1. BeautifoulSoup (bs4)
2. Urllib 
3. queue
4. threading

## How to execute:
1. Generam un virtualenv cu comanda
```
virtualenv -p python3 env && source env/bin/activate
```
2. Instalam dependintele
```
pip install -r requirements.txt
```
3. Executam crawler-ul
```
python main.py www.uab.ro / utf8
```



