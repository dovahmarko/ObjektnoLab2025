#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

double** uns_mtr(int r, int s) {
    double** m = new double*[r];
    for(int i = 0; i < r; i++) {
        m[i] = new double[s];
        for(int j = 0; j < s; j++) {
            std::cin >> m[i][j];
        }
    }
    return m;
}

double** gen_mtr(int r, int s, double p, double k) {
    static bool inic = false;
    if(!inic) {
        srand(time(NULL));
        inic = true;
    }
    double** m = new double*[r];
    for(int i = 0; i < r; i++) {
        m[i] = new double[s];
        for(int j = 0; j < s; j++) {
            m[i][j] = (static_cast<double>(rand()) / RAND_MAX) * (k - p) + p;
        }
    }
    return m;
}

double** zbr_mtr(double** m1, double** m2, int r, int s) {
    double** rez = new double*[r];
    for(int i = 0; i < r; i++) {
        rez[i] = new double[s];
        for(int j = 0; j < s; j++) {
            rez[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return rez;
}

double** odz_mtr(double** m1, double** m2, int r, int s) {
    double** rez = new double*[r];
    for(int i = 0; i < r; i++) {
        rez[i] = new double[s];
        for(int j = 0; j < s; j++) {
            rez[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return rez;
}

double** mnz_mtr(double** m1, int r1, int s1, double** m2, int r2, int s2) {
    if(s1 != r2) {
        return nullptr;
    }
    double** rez = new double*[r1];
    for(int i = 0; i < r1; i++) {
        rez[i] = new double[s2];
        for(int j = 0; j < s2; j++) {
            rez[i][j] = 0;
            for(int k = 0; k < s1; k++) {
                rez[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return rez;
}

double** trp_mtr(double** m, int r, int s) {
    double** rez = new double*[s];
    for(int i = 0; i < s; i++) {
        rez[i] = new double[r];
        for(int j = 0; j < r; j++) {
            rez[i][j] = m[j][i];
        }
    }
    return rez;
}

void isp_mtr(double** m, int r, int s) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < s; j++) {
            std::cout << std::fixed << std::setprecision(4) << std::setw(10) << m[i][j];
        }
        std::cout << std::endl;
    }
}

void obr_mtr(double** m, int r) {
    for(int i = 0; i < r; i++) {
        delete[] m[i];
    }
    delete[] m;
}

int main() {
    int r = 2, s = 2;
    double** m1 = uns_mtr(r, s);
    double** m2 = gen_mtr(r, s, 0.0, 10.0);
    isp_mtr(m1, r, s);
    isp_mtr(m2, r, s);
    double** zbr = zbr_mtr(m1, m2, r, s);
    isp_mtr(zbr, r, s);
    double** odz = odz_mtr(m1, m2, r, s);
    isp_mtr(odz, r, s);
    double** mnz = mnz_mtr(m1, r, s, m2, r, s);
    if(mnz) {
        isp_mtr(mnz, r, s);
    }
    double** trp = trp_mtr(m1, r, s);
    isp_mtr(trp, s, r);
    obr_mtr(m1, r);
    obr_mtr(m2, r);
    obr_mtr(zbr, r);
    obr_mtr(odz, r);
    if(mnz) obr_mtr(mnz, r);
    obr_mtr(trp, s);
    return 0;
}