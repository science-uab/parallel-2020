# ThreadDesenare

### Nume Proiect: Desenare prin fire de executie

##### Autor: STEAU MIHAI LUCIAN

##### Descriere: 
 ######  -_prin acest proiect, putem întelege mai bine ce însemnă firele de execuție, cum funcționează și ce avantaje au.Ideea proiectul a plecat de la un laborator, urmând ca mai apoi să îl îmbunătățesc._

##### Proiectul conține:

1: buton pentru oprire program/ stop

2: buton pentru curătare/ restart

3: buton pentru schimbare formuri / Form1, Form 3

4: butoane pentru activare thread-uri

##### Tehnologii folosite: Microsoft Visual Studio Community 2019 Version 16.4.2  C#

##### Biblioteci externe:

 [Desenare elipsa](https://docs.microsoft.com/en-us/dotnet/api/system.drawing.graphics.drawellipse?view=netframework-4.8)
 
 [Desenare dreptunghi/patrat](https://docs.microsoft.com/en-us/dotnet/api/system.drawing.graphics.drawrectangle?view=netframework-4.8)
 
 [Schimbare form cu ajutorul butoanelor](https://www.experts-exchange.com/questions/23839339/Switching-between-Forms-in-C.html)
 
 [Despre fire de executie](https://www.pluralsight.com/guides/how-to-write-your-first-multi-threaded-application-with-c)
 
 [Exemplu de thread](https://www.c-sharpcorner.com/article/understanding-multithreading-and-multitasking-in-c-sharp/)
 
 [Fire de executie-principii](http://marvinproject.sourceforge.net/en/tutorials/03_multithreading/multithreading.html)
 
[Teorie](https://foxlearn.com/articles/multi-threading-in-csharp.html)

##### Biblioteci interne: bucăți de cod din proiecte mai vechi și teme de laborator

#### Cum se compilează/ rulează:
![logo](https://github.com/steaumihai/ThreadDesenare/blob/master/Screen/2020-01-15_LI%20(2).jpg "Pornine")

După pornirea aplicației, utilizatorul poate să exploreze și să testeze cu ajutorul butoanelor thredurile și să afle ce se va afisa.
![pornire](https://github.com/steaumihai/ThreadDesenare/blob/master/Screen/2020-01-15%20(4)_LI.jpg "butoane")

_În imaginea de mai în sus putem vedea că deși încă rulează firele de execuție, la apăsarea butonului de Stop, va apărea un pop-up dacă
chiar suntem siguri că dorim să oprim procesul. Dacă da, atunci se vor opri toate firele de executie._ 

![Schimbare](https://github.com/steaumihai/ThreadDesenare/blob/master/Screen/2020-01-15%20(5)_LI.jpg "swich")
Prin apăsarea butonului, se va asunde primul form și va apărea al doilea și viceversa.

#### A se vedea likul din biblioteca externa, pentru a intelege codul de schimbare

![Schimare](https://github.com/steaumihai/ThreadDesenare/blob/master/Screen/2020-01-15%20(8).png "swch")

      Form3 temp = new Form3();
            temp.Region = this.Region;
            temp.Show();
            this.Hide();
    
    
 Form secundar:
 ![ds](https://github.com/steaumihai/ThreadDesenare/blob/master/Screen/2020-01-15%20(6)_LI.jpg "secondform")
 
 #### Pentru a creea, pop-up cu mesaj/ codul pentru casuța care se deschide când apăsăm butonul de închidere
 
 
    if (MessageBox.Show("Inchidere program. Confirm?", "Inchidere Program", MessageBoxButtons.YesNo) == DialogResult.Yes)
 
            {
           
                MessageBox.Show("Programul se va inchide cu succes.", "Program inchis!", MessageBoxButtons.OK);
             
                System.Windows.Forms.Application.Restart();
             
            }
         
            else
          
           {
           
               this.Activate();
            
            }
           
 
