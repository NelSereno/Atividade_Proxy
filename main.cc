#include <iostream>

class Image{
	public:
	virtual void display() = 0;
};

class RealImage: public Image{
	public:
	std::string fileName;
	void loadFromDisk(std::string fileName){
		std::cout << "Carregando " << fileName << std::endl;
	};
	RealImage(std::string fileName){
		this->fileName = fileName;
		loadFromDisk(fileName);
	};
	void display() override{	
		std::cout << "Displaying " << fileName << std::endl;
	};
};

class ProxyImage: public Image{
	public:
	RealImage* realImage;
	std::string fileName;
	ProxyImage(std::string fileName){
		this->fileName = fileName;
	};
	void display() override{
		if(realImage == NULL)
			realImage = new RealImage(fileName);
		realImage->display();
	};
};

int main(){
	Image* image = new ProxyImage("test_10mb.jpg");
	image->display();
	std::cout << std::endl;
	image->display();
}