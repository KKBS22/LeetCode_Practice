#include<iostream>
#include<vector>
#include<stack>
#include<regex>
#include<algorithm>

#define SPEED 1

using namespace std;


enum Direction {Left=0, Right=1, NOD=2};

typedef struct Hit {
	float time = 0.0;
      	int count = 0;
	float pos = 0.0;
	Direction m_dir = NOD;	
}Hit_t;

class Monkey {
	private:
		int monkey_id;
		float position;
		bool is_alive;
		//stack<Hit_t> hit_list;
	public:
		Monkey() {}
		~Monkey() {}

		Monkey(int monkey_id, float position, bool is_alive) : monkey_id{monkey_id}, position{position}, is_alive{is_alive} {}
		
		// Getters and Setters:
		int get_monkey_id() {
			return this->monkey_id;
		}
		void set_monkey_id(int id) {
			this->monkey_id = id;
		}

		float get_position() {
			return this->position;
		}
		void set_position(float pos) {
			this->position = pos;
		}

		bool get_is_alive() {
			return this->is_alive;
		}

		void set_is_alive(bool stat) {
			this->is_alive = stat;
		}

};

class Board {

		int size;
		int no_of_players;
		float start_pos;
		float end_pos;
			
	public:
		Board() {}
		~Board() {}

		Board(int size,int no_of_players, float start_pos, float end_pos) : size{size}, no_of_players{no_of_players}, start_pos{start_pos}, end_pos{end_pos} {}

		virtual void start_sim();
		virtual void init_players(vector<float> position_data);	
		virtual void show_players();
		virtual void show_config();
};

class MonkeyBoard {

	private: 
		int size;
		int num_of_monkey;
		float start_pos;
		float end_pos;
		vector<Monkey> monkey_list;
	public:

		MonkeyBoard() {}
		~MonkeyBoard() {}

		MonkeyBoard(int size, int num_of_monkey, float start_pos, float end_pos) : size{size}, num_of_monkey{num_of_monkey}, start_pos{start_pos}, end_pos{end_pos} {}
		
		void start_sim() {
			cout << "----------Starting simulation------------" << endl;
			cout << "------------End Simulation---------------" << endl;
		}

		void init_players (vector<float> position_data) {
			cout << "----------Starting to Init Players----------------" << endl;
			if (position_data.size() > num_of_monkey) {
				cerr << "Invalid size of position argument, should be of size : " << num_of_monkey << "  but given size : " << position_data.size(); 
				exit(1);
			} else {
				for (int i = 0 ; i < num_of_monkey; i++) {
					this->monkey_list.push_back(Monkey(i,position_data[i], true));					
				}
			}
			cout << "Created monkeyes : " << this->monkey_list.size() << endl;
			cout << "----------Finished initialization-----------------" << endl;	
		}

		void show_players() {
			for (int j = 0; j < this->monkey_list.size(); j++ ) {
				cout << "------------------------------" << endl;
				cout << "The Monkey ID is : " << this->monkey_list[j].get_monkey_id() << endl;
				cout << "The Monkey poistion is : " << this->monkey_list[j].get_position() << endl;
				cout << "The Monkey Status id : " << this->monkey_list[j].get_is_alive() << endl;
				cout << "------------------------------" << endl;
			}
		}

		void show_config() {
			cout << "-----------------------------------" << endl;
			cout << "Number of monkey on board : " << this->num_of_monkey << endl;
			cout << "Board start : " << this->start_pos << endl;
			cout << "Board end : " << this->end_pos << endl;
			cout << "Board size : " << this->size << endl;
			cout << "-----------------------------------" << endl;
		
		}						

};


vector<float>
parse_player_data() {
	vector<float> player_pos{0.0,1.1,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
	return player_pos;
}



int
main(int argc, char* argv[]) {
		
	MonkeyBoard *test_sim =  new MonkeyBoard(10, 10, 0.0, 10.0);
	
	vector<float> player_pos = parse_player_data();
	test_sim->init_players(player_pos);
	
	test_sim->show_config();
	test_sim->show_players();

	
	delete test_sim;
	return EXIT_SUCCESS;
}
