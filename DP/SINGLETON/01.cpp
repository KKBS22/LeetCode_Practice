#include<iostream>

class SettingsConfig {

	private:
		int width;
		int height;
		float brightness;
		
		static SettingsConfig* _instance;
		SettingsConfig() : width{100}, height{200}, brightness{80} {}

	public:
		static SettingsConfig* get_instance() {
			if (_instance == NULL) {
				_instance = new SettingsConfig();
			}
			return _instance;
		}

		void print_data() {
			std::cout << "The Width : " << width << " The height : " << height << " The brightness : " << brightness << std::endl;
		}

		int get_height() {
			return height;
		}

		int get_width() {
			return width;
		}

		float get_brightness() {
			return brightness;
		}

		void set_height(int ht) {
			this->height = ht;
		}

		void set_width(int wt) {
			this->width = wt;
		}

		void set_bright(float bt) {
			this->brightness = bt;
		}

};


SettingsConfig* SettingsConfig::_instance = NULL;


int main() {
	SettingsConfig* setting_data = SettingsConfig::get_instance();	
	setting_data->print_data();
	std::cout << "The address of setting instance is : " << setting_data << std::endl;
	SettingsConfig* setting_data_two = SettingsConfig::get_instance();
	setting_data_two->print_data();
	auto test = setting_data_two == setting_data ? true : false;
	std::cout << "Is this the same : " << test << std::endl;

	delete setting_data;

}
