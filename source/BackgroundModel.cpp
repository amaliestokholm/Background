#include "BackgroundModel.h"


// BackgroundModel::BackgroundModel()
//
// PURPOSE: 
//      Constructor. Initializes model computation.
//
// INPUT:
//      covariates:             one-dimensional array containing the values
//                              of the independent variable.
//

BackgroundModel::BackgroundModel(const RefArrayXd covariates)
: Model(covariates)
{
}










// BackgroundModel::BackgroundModel()
//
// PURPOSE: 
//      Destructor.
//

BackgroundModel::~BackgroundModel()
{

}











// BackgroundModel::getResponseFunction()
//
// PURPOSE:
//      Gets the protected data member responseFunction.
//
// OUTPUT:
//      An eigen array containing the apodization response function for the signal of the input data
//

ArrayXd BackgroundModel::getResponseFunction()
{
    return responseFunction;
}








// BackgroundModel::NyquistFrequency()
//
// PURPOSE:
//      Gets the protected data member NyquistFrequency.
//
// OUTPUT:
//      A double containing the Nyquist frequency for the given cadence adopted.
//

double BackgroundModel::getNyquistFrequency()
{
    return NyquistFrequency;
}











// BackgroundModel::readNyquistFrequencyFromFile()
//
// PURPOSE:
//      Reads the Nyquist frequency of the dataset from an input ASCII file.
//
// INPUT:
//      inputFileName:      a string specifying the full path (filename included) of the input file to read.
//
// OUTPUT:
//      void
//

void BackgroundModel::readNyquistFrequencyFromFile(const string inputFileName)
{
    ifstream inputFile;
    File::openInputFile(inputFile, inputFileName);

    unsigned long Nrows;
    int Ncols;

    File::sniffFile(inputFile, Nrows, Ncols);
    ArrayXd inputData;
    inputData.resize(Nrows);

    inputData = File::arrayXXdFromFile(inputFile, Nrows, Ncols);
    NyquistFrequency = inputData(0);

    inputFile.close();
}



// BackgroundModel::writeHyperParametersToFile()
//
// PURPOSE:
//      Store prior hyper parameters in an output ASCII file.
//
// INPUT:
//      fullPath:     a string containing the full filename for the output ASCII file
//
// OUTPUT:
//      void
//

void BackgroundModel::writeHyperParametersToFile(string fullPath)
{
    ofstream outputFile;
    File::openOutputFile(outputFile, fullPath);
    outputFile << "# Hyper parameters used for setting up priors." << endl;
    outputFile << "# Each line corresponds to a different free parameter (coordinate)." << endl;
    outputFile << "# Column #1: Left prior boundary parameter" << endl;
    outputFile << "# Column #2: Right prior boundary parameter" << endl;
    outputFile << "# Column #3: Type of prior" << endl;

    // File::threeArrayXdToFile(outputFile, left, right, priorcases);
    outputFile.close();
}

