#ifndef C_DROPKI_H
#define C_DROPKI_H

class Dropki {
private:
    int broitel,imenitel;
public:
    Dropki();
    void setDropki(int broitel1, int imenitel1);
    int getBroitel();
    int getImenitel();
    void ispechati();
    void ispechatiRealenBroj();
    Dropki operator+(Dropki dropki);
    Dropki operator-(Dropki dropki);
    Dropki operator*(Dropki dropki);
    Dropki operator/(Dropki dropki);
    Dropki operator+(int broj);
    Dropki operator-(int broj);
    Dropki operator*(int broj);
    Dropki operator/(int broj);
};

#endif