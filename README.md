Kod testujący implemetnację struktur danych 

Powyższy kod przedstaiwa implementację następujących struktur:
- Pojedyńczo wiązana lista (SingleLinkedList)
- Podwójnie wiązana lista (DoubleLinkedList)
- Tablica Dynamiczna (Dynamic Array)

W klasie main znajduje się:

- Menu uruchomieniowe, któr służy do utworzenia obiektów, oraz wykonania testów dla danej struktury.
- 3 metody których zadaniem jest testowanie poszczególnych struktur:
    - testIntSLL - metoda testująca pojedynczo wiązaną listę
    - testIntDLL - metoda testująca podwójnie wiązaną listę
    - testDA - metoda testująca tablicę dynamiczna
- metody pomocnicze:
    - printOperationTime - metoda do drukowania na konsole
    - timeCountLogger - metoda odpowiedzialna za logowanie do linku csv, w folderze data

Pierwotnie koncepcyjnie kod powinien testować struktury na następuących typach danych:

 int,char,float,double,srting, lecz niestety, z powodu przedłużającego się czasu wyszukiwania problemu związanego z użyciem generychych metod, zredukowano testowane typy do int. 

Na podstawie wyników pomiaru, zostały utworzone wykresy poszczególnych oepracji dla danych struktur danych. Cała wiedza teoretyczna jak i również wykresy pomiarów zostałt zawarte w sprawozdaniu.


<object data="[http://yoursite.com/the.pdf](https://github.com/MichalBialek01/DataStructuresTest/blob/master/DataStructures_report.pdf)" type="application/pdf" width="700px" height="700px">
    <embed src="[http://yoursite.com/the.pdf](https://github.com/MichalBialek01/DataStructuresTest/blob/master/DataStructures_report.pdf)">
        <p>This browser does not support PDFs. Please download the PDF to view it: <a href="[http://yoursite.com/the.pdf](https://github.com/MichalBialek01/DataStructuresTest/blob/master/DataStructures_report.pdf)">Download PDF</a>.</p>
    </embed>
</object>
