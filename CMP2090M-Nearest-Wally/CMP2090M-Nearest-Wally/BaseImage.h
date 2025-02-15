#pragma once
class BaseImage
{
public:
	//Accessor & Mutator functions
	double* getImage();
	void setImage(double* img);
	void setImgValue(int loc, double indv);
	double getImgValue(int loc);
	double getImgValue(int row, int col);

	// Default constructor/destructor
	BaseImage();
	~BaseImage();

	//Constructors
	BaseImage(const int rows, const int cols);
	BaseImage(double* data);
	
	int sizeR, sizeC, size;

protected:
	double* img; // Store the image as a protected variable
};

