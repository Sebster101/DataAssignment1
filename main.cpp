//Main
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]){
	//empty string for file to input
	string fileName = "";
	//files to write to
	ofstream fileWrite("Ludlow.out", ios::trunc);
	ofstream fileGauss("Gauss.out", ios::trunc);
	//writes intro to file Ludlow
	fileWrite << "Sebastian Ludlow \nID:2290555 \nAssignment 1";
	//checks and allows for multiple runs of program
	bool isRunning = true;
	while (isRunning == true){
		//user enters file they want to be working with
		cout << "Enter the file to be used including extensions:";
		cin >> fileName;
		ifstream fileRead(fileName.c_str());
		//variables to be used in calculating the nucleotides
		string lineReader = "";
		int lineCount = 0;
		double countA = 0;
		double countC = 0;
		double countT = 0;
		double countG = 0;
		double countAA = 0;
		double countCC = 0;
		double countTT = 0;
		double countGG = 0;
		double totalA = 0;
		double totalC = 0;
		double totalT = 0;
		double totalG = 0;
		double localTotal = 0;
		double total = 0;
		double meanA = 0;
		double meanC = 0;
		double meanT = 0;
		double meanG = 0;
		double meanLength = 0;
		double percentA = 0;
		double percentC = 0;
		double percentT = 0;
		double percentG = 0;
		double var = 0;
		double varTotal = 0;
		double standardDev = 0;
		//reads each independent line of the text file
		while(getline(fileRead, lineReader)){
			//variables reset for individual line counting purposes
			lineCount++;
			countA = 0;
			countC = 0;
			countT = 0;
			countG = 0;
			countAA = 0;
			countCC = 0;
			countTT = 0;
			countGG = 0;
			localTotal = 0;
			bool bigramCheckA = false;
			bool bigramCheckC = false;
			bool bigramCheckT = false;
			bool bigramCheckG = false;
			//for loops to count total nucleotides and bigrams
			for(int i=0; i < lineReader.length(); i++){
				if(lineReader[i] == 'a' || lineReader[i] == 'A'){
					if (bigramCheckA == true){
						countAA++;
					}

					countA++;
					totalA++;
					localTotal++;
					total++;
					bigramCheckA = true;
					bigramCheckC = false;
					bigramCheckT = false;
					bigramCheckG = false;
				}else if (lineReader[i] == 'c' || lineReader[i] == 'C'){
					if (bigramCheckC == true){
						countCC++;
					}
					countC++;
					totalC++;
					localTotal++;
					total++;
					bigramCheckA = false;
					bigramCheckC = true;
					bigramCheckT = false;
					bigramCheckG = false;
				}else if (lineReader[i] == 't' || lineReader[i] == 'T'){
					if (bigramCheckT == true){
						countTT++;
					}
					countT++;
					totalT++;
					localTotal++;
					total++;
					bigramCheckA = false;
					bigramCheckC = false;
					bigramCheckT = true;
					bigramCheckG = false;
				}else if (lineReader[i] == 'g' || lineReader[i] == 'G'){
					if (bigramCheckG == true){
						countGG++;
					}
					countG++;
					totalG++;
					localTotal++;
					total++;
					bigramCheckA = false;
					bigramCheckC = false;
					bigramCheckT = false;
					bigramCheckG = true;
				}
				//calculations for variance and standard deviation
				meanLength = total/lineCount;
				var = localTotal - meanLength;
				varTotal = var + varTotal;
				standardDev = sqrt(varTotal);

			}
			//mean calculations for nucelotides
			meanA = countA/localTotal;
			meanC = countC/localTotal;
			meanT = countT/localTotal;
			meanG = countG/localTotal;

			//writes stats for each line to file Ludlow
			fileWrite << "\nDna String " << lineCount << ": " << "A: " << countA << " C: " << countC << " T: " << countT << " G: " << countG << " Total: " << localTotal << " Brigam A: " << countAA << " Brigam C: " << countCC << " Brigam T: " << countTT << " Brigam G: " << countGG << " Mean A: " << meanA << " Mean C: " << meanC << " Mean T: " << meanT << " Mean G: " << meanG;
		}
		//calculations for averages
		meanA = totalA / total;
		meanC = totalC / total;
		meanT = totalT / total;
		meanG = totalG / total;
		percentA = meanA*100;
		percentC = meanC*100;
		percentT = meanT*100;
		percentG = meanG*100;


		//writes to file Ludlow final totals
		fileWrite << "\nTotals: " << " A: " << totalA << " C: " << totalC<< " T: " << totalT << " G: " << totalG << " Total: " << total << "\nMean: " << " A: " << meanA << " C: " << meanC << " T: " << meanT << " G: " << meanG << " Variance: " << varTotal << " Standard Deviation: " << standardDev;
		srand (time(NULL));
		//writes out random string of 1000 nucleotides to Gauss.txt
		for (int i = 0; i < 1000; i++)
		{
			int integer = rand() % 100;
			if (integer < (percentA)){
				fileGauss << "A";
			} else if (integer < (percentA+percentC)){
				fileGauss << "C";
			} else if (integer < (percentA+percentC+percentT)){
				fileGauss << "T";
			} else if (integer < (percentA+percentC+percentT+percentG)){
				fileGauss << "G";
			}
		}
		//closes file reader
		fileRead.close();

		//asks user if they want to run again
		string decision = "";
		int x = 0;
		while (x == 0){
			cout << "\nType Y to continue or N to exit: ";
			cin >> decision;
			//allows user to continue program
			if (decision == "Y" || decision == "y"){
				x = 1;
			//exits the program
			} else if (decision == "N" || decision == "n"){
				isRunning = false;
				x = 1;
			//catches invalid options
			} else {
				cout << "\nInvalid Option";
			}
		}

	}


}