#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) {
  return pow(mu, k)*exp(-mu)/tgamma(k+1);
}

double prob(std::vector<int> daten, double mu) {
  double i = 1;
  for(int k : daten) {
    i *= poisson(mu, k);
  }
  return i;
}

double probk(std::vector<int> daten) {
  double i = 1;
  for(int k : daten) {
    double a = 1.0 * k;
    i *= poisson(a, k);
  }
  return i;
}

int main() {
  using namespace std;

  vector<int> daten;
  ifstream fin("datensumme.txt");
  int n_i;
  for(int i = 0 ; i < 234 ; ++i) {
    fin >> n_i;
    daten.push_back(n_i);
  }
  
  double mu;
  double mu_lower = 0.0;
  double mu_upper = 6.0;
  double step_size = 0.05;

  for(mu=mu_lower; mu<=mu_upper; mu+=step_size) {
    double lambda;
    lambda = prob(daten, mu)/probk(daten);
    cout << (-2*log(lambda)-233)/sqrt(2*233) << endl;
  }

  fin.close();
}