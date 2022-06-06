#include<iostream>
#include<vector>
#include<string>

class Product;

class IBuilder {
	public:
		virtual void BuildBody() = 0;
		virtual void BuildWheels() = 0;
		virtual Product* GetVechicle() = 0;
};


class Product {
	private:
		std::vector<std::string> prod_list;
	public:
		Product();
		~Product();

		void Add(string part) {
			prod_list.push_back(part);
		}

		void Show() {
			for (const auto &item : prod_list) {
				std::cout << "The part : " << item << std::endl;
			}
		}

}


class Car : public IBuilder {
	private:
		std::string vname;
		Product* pd = new Product();
	public:
		Car();
		~Car();

		Car(std::string name) : vname{name} {}

		void BuildBody() {
			std::cout << "Building car body" << std::endl;
			pd->Add("Car Body");
		}

		void BuildWheels() {
			std::cout << "Building car wheels" << std::endl;
			pd->Add("Car Wheels");
		}

		Product* GetVehicle() {
			return pd;
		}	
};


class Bike : public IBuilder {
	private:
		std::string bname;
		Product* pd = new Product();
	public:
		Bike();
		~Bike();

		Bike(std::string name) : bname{name} {}

		void BuildBody() {
			std::cout << "Building bike body" << std::endl;
			pd->Add("Bike Body");
		}

		void BuildWheels() {
			std::cout << "Building bike wheels" << std::endl;
			pd->Add("Bike Wheels");
		}

		Product* GetVehicle() {
			return pd;
		}
};






int main() {
	return EXIT_SUCCESS;
}



















