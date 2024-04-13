# Tablice dynamiczne

W języku c++ możemy stosować różne rodzaje podejść do stosowania tablic dynamicznych. 

1. Przy pomocy operatora new[] i delate[]. Nie jest on bezpieczny, ze względu na bezpieczeństwo, a mianowicie programista możę się pomylić, podczas ręcznego zarządzania pamięcią.
2. Kożystając z biblioteki STL vector, array, deque. Są one bezpieczne, ponieważ oferują wbudowane metody do manipulacji danymi. 
3. Wycieki pamięci - analiza valgrind

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

# Wstęp teoretyczny

### 1. Tablice dynamiczne

Do pełnego zrozumienia tablicy dynamicznych ważne jest rozumienie jakie jest powiązanie pomiędzy wskaźnikami a tablicami dynamicznymi.

1. Wskaźniki
    1. Co to są wskaźniki (pointer):
        
        jest to typ zmiennej, który wskazuje na adres zmiennej. Może wskazywać na różne obiekty (zmienną, tablicę, funkcję, strukturę, lub klasę)
        
    2. Operatory 
        
        Do operacji na wskaźnikach kożystamy z operatorów:
        
        * - operator wydobywania wartości zmiennej na którą wskazuje wskaźnik]
        
        & - operator pobrania adresu zmiennej
        
    3. Zalety stosowania wskaźników
        
        Zwiększenie wydajności programu
        
        Zmniejszenie zużycia pamięci
        
    4. Dlaczego stosujemy wskaźniki ?
        
        Język c++ przekazuje do metody argumenty poprzez wartość (pass by value), co oznacza, że w obrębie metody operujemy na kopiach przekazanych wartościach (duża zasobożerność)
        
        Wysyłając wskaźniki do metod, powoduje, że operujemy na orginalnych danych, więc nie marnujemy pamięci, i mamy możliwośc pracy na orginalnych danych
        

## 2. Lista wiązana - linked lista

[Program - opis](https://www.notion.so/Program-opis-f1cfa73922784ddeab311fde39d72cb2?pvs=21)

[Opisy implementacji ](https://www.notion.so/Opisy-implementacji-a7edf9c0aae74318a0bfb2d47e257d57?pvs=21)
