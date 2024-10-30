#include <iostream>

double sqrt(double x) {
    if (x < 0) {return -1;}
    if (x == 0) {return 0;}

    double low = 0, high = x; 
    double tolerance = 1e-10;

    if (x < 1) {high = 1;}

    while (high - low > tolerance) {
        double mid = (high + low) / 2.0; 
        if (mid * mid < x) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return (high + low) / 2.0;
}

double calculateDistance(int x1, int y1, int x2, int y2) {
    double res; 
    res = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return res; 
}

double calculateAbs(double x) {return (x >= 0) ? x : -x;}

void solveCircles(double dist, int r1, int r2) {
    if (dist + r1 <= r2) {
        std::cout << "Да" << std::endl;
    } else if (dist + r2 <= r1) {
        std::cout << "Да, но справделиво обратное для двух" << std::endl;
    } else if (dist < r1 + r2 && dist > calculateAbs(r1 - r2)) {
        std::cout << "Фигуры пересекаются" << std::endl; 
    } else {
        std::cout << "Ни одно условие не выполнено" << std::endl;
    }
}

int main() {
    int x1, y1, r;
    std::cout << "Введите пожалуйста координаты и радиус для первого круга: ";
    std::cin >> x1 >> y1 >> r; 
    int x2, y2, R; 
    std::cout << "Введите пожалуйста координаты и радиус для второго круга: ";
    std::cin >> x2 >> y2 >> R;

    double d = calculateDistance(x1, y1, x2, y2);

    solveCircles(d, r, R); 
    
    return 0;
}


/*
//функция для подсчета модуля числа
int abs(int x) { return (x > 0 ? x : -x); }


void solveCircles(int x1, int y1, int r1, int x2, int y2, int r2) {
    //рассчитываем внутренний шаг по Ox и по Oy
    int innerStep = abs(x1 - x2) + abs(y1 - y2);
    
    //проверяем радиусы на равенство
    bool bothEqual = r1 == r2;
    //находим наибольшой радиус
    int rMax = 0, rMin = 0;
    if(!bothEqual) {
        if (r1 > r2) { rMax = r1; rMin = r2; }
        else { rMax = r2; rMin = r1; }
    }

    //алгоритм
    //1.если центры кругов равны и радиусы равны
    if(!innerStep && bothEqual) { cout << "Круги пересекаются"; }\

    //2.если центры кругов равны, радуисы НЕравны
    else if(!innerStep && !bothEqual) { cout << (rMin == r1) ? "Круг 1 попадает в круг 2" : "Круг 2 попадает в круг 1"; }

    //3.если центры кругов НЕравны и радиусы НЕравны
    else if(!innerStep && !bothEqual) {

        //3.1.если сумма мин. радиуса и внутренеего шага НЕ превышает зн-ие макс. радуиса
        if (rMin + innerStep <= rMax) { cout << (rMin == r1) ? "Круг 1 попадает в круг 2" : "Круг 2 попадает в круг 1"; }
        
        //3.2.если сумма мин. радиуса и внутреннего шага ПРЕВЫШАЕТ зн-ие макс. радиуса
        else {
            if(innerStep <= rMax + rMin) { cout << "Круги пересекаются"; }
            else {
                cout << "Ни одно условие не выполнимо";
            }
        }
    }
 

}

int main() {
    cout << "Пожалуйста введите M1(x1, y1) значения для x1, y1 и r1: ";
    int x1, y1, r1; cin >> x1 >> y1 >> r1;
    cout << "Пожалуйста введите M2(x2, y2) значения для x2, y2 и r2: "; 
    int x2, y2, r2; cin >> x2 >> y2 >> r2; 
    //ввызов основной функции
    solveCircles(x1, y1, r1, x2, y2, r2);
    return 0; 
}
*/