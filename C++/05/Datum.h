#ifndef C_DATUM_H
#define C_DATUM_H

class Datum {
public:
    Datum();
    Datum(int den_in, int mesec_in, int godin_in);
    int getDen();
    int getMesec();
    int getGodina();
    void ispecatiDatum() const;
private:
    int den;
    int mesec;
    int godina;
};

#endif
