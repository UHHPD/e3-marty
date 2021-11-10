#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) {
  return pow(mu, k)*exp(-mu)/tgamma(k+1);
}

int main() {
  using namespace std;

  vector<int> zaehler(11);
  ifstream fin("datensumme.txt");
  ofstream fout("histpoi.txt");
  int n_i;
  int zahl;
  for(int i = 0 ; i < 234 ; ++i) {
    fin >> n_i;
    zahl = n_i;
    zaehler[zahl] += 1;
  }
  fin.close();

  for(unsigned int k = 0 ; k < zaehler.size() ; ++k) {
    cout << k << ":" << zaehler[k] << endl;
    fout << k << " " << zaehler[k] << " " << 234*poisson(3.11538, k) << endl;
  }
  fout.close();
}