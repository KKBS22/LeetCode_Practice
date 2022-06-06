#include<iostream>


class SettingTest {
	private:
		int width;
		static SettingTest* _instance;
		SettingTest() : width{100} {}
	public:
	
		static SettingTest* get_instance() {
			if (_instance == NULL) {
				_instance = new SettingTest();
			}
			return _instance;
		}

		int get_width() {
			return width;
		}

		void set_width(int wd) {
			this->width = wd;		
		}

		void print_settings() {
			std::cout << "The width is : " << this->width << std::endl;
		}

};

SettingTest* SettingTest::_instance = NULL;

int 
main(int argc, char* argv[]) {
	SettingTest* test_instance = SettingTest::get_instance();
	std::cout << "The address of the instance is : " << test_instance << std::endl;
	test_instance->print_settings();

	return EXIT_SUCCESS;

}
