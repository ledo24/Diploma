// Diploma.cpp : Programsko ogordje za razvoj stohastičnih algoritmov
// Avtor       : Klemen Ledinek
// Datum	   : 28.02.2019

#include "stdafx.h"
#include "DifferentialEvolution.h"
#include "ParticleSwarmOptimization.h"
#include "GeneticAlgorithm.h"
#include "Wilcoxon_Test.h"
#include "Threads.h"
#include "Problemi.h"

void writeToFile(vector<double> p_vector, int func_num, string p_name) {
	string name = p_name + to_string(func_num);
	ofstream file;
	file.open(name, std::ios_base::app);
	for (int i = 0; i < 20; i++) {
		file << p_vector[i] << endl;
	}
	file.close();
}

void doGA() {
	double* problemcic = new double[1];
	int time = 60;
	string name = "GA_FUNC";
	//1
	vector<double> w_vector = vector<double>(20);
	problemcic[0] = 1;
	GeneticAlgorithm novGA = GeneticAlgorithm(problemcic, 9, 0.3, 500, 0, time, -8192.00, 8192.00, 1000.00, 0.3, 0.0000000005);
	for (int j = 0; j < 20; j++) {
		novGA.init();
		w_vector[j] = novGA.get_bestFitnes();
		novGA.refresh();
	}
	writeToFile(w_vector, 1, name);
	//2
	
	w_vector = vector<double>(20);
	problemcic[0] = 2;
	GeneticAlgorithm novGA1 = GeneticAlgorithm(problemcic, 16, 0.3, 500, 0, time, -16384.00, 16384.00, 1000.00, 0.3, 0.0000000005);
	for (int j = 0; j < 20; j++) {
		novGA1.init();
		w_vector[j] = novGA1.get_bestFitnes();
		novGA1.refresh();
	}
	writeToFile(w_vector, 2, name);
	
	//3
	w_vector = vector<double>(20);
	problemcic[0] = 3;
	GeneticAlgorithm novGA2 = GeneticAlgorithm(problemcic, 18, 0.3, 500, 0, time, -4.00, 4.00, 50.00, 0.3, 0.0000000005);
	for (int j = 0; j < 20; j++) {
		novGA2.init();
		w_vector[j] = novGA2.get_bestFitnes();
		novGA2.refresh();
	}
	writeToFile(w_vector, 3, name);

	

	for (int i = 4; i < 11; i++) {
		vector<double> w_vector = vector<double>(20);
		problemcic[0] = i;
		GeneticAlgorithm novGA = GeneticAlgorithm(problemcic, 10, 0.3, 500, 0, time, -100.00, 100.00, 50.00, 0.3, 0.0000000005);
		for (int j = 0; j < 20; j++) {
			novGA.init();
			w_vector[j] = novGA.get_bestFitnes();
			novGA.refresh();
		}
		writeToFile(w_vector, i, name);
	}
}

void doDE() {
	double* problemcic = new double[1];
	int time = 60;
	string name = "DE_FUNC";

	//1
	vector<double> w_vector = vector<double>(20);
	problemcic[0] = 1;
	DifferentialEvolution novDE = DifferentialEvolution(problemcic, 9, 0.3, 500, 0, time, -8192.00, 8192.00, 0.3, 0.0000000005);
	for (int j = 0; j < 20; j++) {
		novDE.init();
		w_vector[j] = novDE.get_bestFitnes();
		novDE.refresh();
	}
	writeToFile(w_vector, 1, name);
	//2

	w_vector = vector<double>(20);
	problemcic[0] = 2;
	DifferentialEvolution novDE1 = DifferentialEvolution(problemcic, 16, 0.3, 500, 0, time, -16384.00, 16384.00, 0.3, 0.0000000005);
	for (int j = 0; j < 20; j++) {
		novDE1.init();
		w_vector[j] = novDE1.get_bestFitnes();
		novDE1.refresh();
	}
	writeToFile(w_vector, 2, name);

	//3
	w_vector = vector<double>(20);
	problemcic[0] = 3;
	DifferentialEvolution novDE2 = DifferentialEvolution(problemcic, 18, 0.3, 500, 0, time, -4.00, 4.00,0.3, 0.0000000005);
	for (int j = 0; j < 20; j++) {
		novDE2.init();
		w_vector[j] = novDE2.get_bestFitnes();
		novDE2.refresh();
	}
	writeToFile(w_vector, 3, name);



	for (int i = 4; i < 11; i++) {
		vector<double> w_vector = vector<double>(20);
		problemcic[0] = i;
		DifferentialEvolution novDE = DifferentialEvolution(problemcic, 10, 0.3, 500, 0, time, -100.00, 100.00, 0.3, 0.0000000005);
		for (int j = 0; j < 20; j++) {
			novDE.init();
			w_vector[j] = novDE.get_bestFitnes();
			novDE.refresh();
		}
		writeToFile(w_vector, i, name);
	}
}

void doPSO() {
	double* problemcic = new double[1];
	int time = 60;
	string name = "PSO_FUNC";
	//1
	vector<double> w_vector = vector<double>(20);
	problemcic[0] = 1;
	ParticleSwarmOptimization novPSO = ParticleSwarmOptimization(problemcic, 9, 500, 0, time, -8192.00, 8192.00, 1000.00, 0.0000000005);
	for (int j = 0; j < 20; j++) {
		novPSO.init();
		w_vector[j] = novPSO.get_bestFitnes();
		novPSO.refresh();
	}
	writeToFile(w_vector, 1, name);
	//2

	w_vector = vector<double>(20);
	problemcic[0] = 2;
	ParticleSwarmOptimization novPSO1 = ParticleSwarmOptimization(problemcic, 16, 500, 0, time, -16384.00, 16384.00, 1000.00, 0.0000000005);
	for (int j = 0; j < 20; j++) {
		novPSO1.init();
		w_vector[j] = novPSO1.get_bestFitnes();
		novPSO1.refresh();
	}
	writeToFile(w_vector, 2, name);

	//3
	w_vector = vector<double>(20);
	problemcic[0] = 3;
	ParticleSwarmOptimization novPSO2 = ParticleSwarmOptimization(problemcic, 18,  500, 0, time, -4.00, 4.00, 50.00,  0.0000000005);
	for (int j = 0; j < 20; j++) {
		novPSO2.init();
		w_vector[j] = novPSO2.get_bestFitnes();
		novPSO2.refresh();
	}
	writeToFile(w_vector, 3, name);



	for (int i = 4; i < 11; i++) {
		vector<double> w_vector = vector<double>(20);
		problemcic[0] = i;
		ParticleSwarmOptimization novPSO = ParticleSwarmOptimization(problemcic, 10,  500, 0, time, -100.00, 100.00, 50.00,  0.0000000005);
		for (int j = 0; j < 20; j++) {
			novPSO.init();
			w_vector[j] = novPSO.get_bestFitnes();
			novPSO.refresh();
		}
		writeToFile(w_vector, i, name);
	}
}


int main()
{
	srand(time(NULL)); //seed of random numbers
	//DE  #DONE
	double* problemcic = new double[1];
	problemcic[0] = 1;
	/*DifferentialEvolution novDe = DifferentialEvolution(problemcic, 10, 0.1, 20, 0, 3, 0.0, 50.0, 0.5, DBL_MIN);
	vector<double> resultDE = novDe.run();
	novDe.wait();
	//PSO #DONE
	ParticleSwarmOptimization novPso = ParticleSwarmOptimization(problemcic, 10, 0.1, 20, 20, 0, 0.0, 50.0, 50.0, DBL_MIN);
	vector<double> resultPSO = novPso.run();
	novPso.wait();
	//GA #DONE
	GeneticAlgorithm novGA = GeneticAlgorithm(problemcic, 10, 0.0, 20, 20, 0, 0.0, 50.0, 50.0, 0.3, DBL_MIN);
	vector<double> resultGA = novGA.run();
	novGA.wait();*/
	//DifferentialEvolution novDe = DifferentialEvolution(problemcic, 10, 0.3, 500, 0, 120, -100.0, 100.0, 0.5, 0.0000000005);
	//ParticleSwarmOptimization novPso = ParticleSwarmOptimization(problemcic, 18, 120, 0, 120, -4.0, 4.0, 4.0, 0.0000000005);
	//GeneticAlgorithm novGA = GeneticAlgorithm(problemcic, 9, 0.3, 500, 0, 120, -8192.0, 8192.0, 1000.0, 0.3, 0.0000000005);
	//vector<double> resitve = vector<double>(10);
	//for (int i = 0; i < 2; i++) {
		
		//novPso.init();
		//resitve[i] = novPso.get_bestFitnes();
	//}
	cout << "GA"<<endl;
	doGA();
	cout << "Konec GA" << endl;

	cout << "DE" << endl;
	doDE();
	cout << "Konec DE" << endl;

	cout << "PSO" << endl;
	doPSO();
	cout << "Konec PSO" << endl;

	cout << "Konec";


}


