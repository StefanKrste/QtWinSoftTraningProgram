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
    void sobiranje (Dropki dropki);
    void odzemanje (Dropki dropki);
    void mnozenje (Dropki dropki);
    void delenje (Dropki dropki);
    void ispechati();
    void ispechatiRealenBroj();
};

#endif

