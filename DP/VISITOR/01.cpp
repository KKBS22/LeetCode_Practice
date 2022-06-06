#include<iostream>
#include<string.h>
#include<memory>

using namespace std;

class ChessComponent {

	private:
		string component_name;
	public:

		ChessComponent();
		~ChessComponent();

		ChessComponent(string name) : component_name{name} {}

		ChessComponent(const ChessComponent& other) {
			this->component_name = other.component_name;
		}
		
		string get_component_name() {
			return this->component_name;
		}

		void set_component_name(string name) {
			this->component_name = name;
		}

		virtual void visit() const = 0;

};


class Piece : public ChessComponent {
	
	private:
		string color;
	public:

		Piece();
		~Piece();

		Piece(string name, string color) : ChessComponent{name} , color{color} {}

		Piece(const Piece& other) {
			this->color = other.color;
		}

		string get_color() {
			return this->color;
		}
		void set_color(string color) {
			this->color = color;
		}

		void visit() const override {
			cout << "Visit in : P "<< endl;
		}

};

class BoardBlock : public ChessComponent {
	
	private:
		string board_color;
		Piece* piece;
	public:
		
		BoardBlock();
		~BoardBlock();

		BoardBlock(string board_color, Piece* piece) : board_color{board_color}, piece{piece} {}

		string get_board_color() {
			return this->board_color;
		}

		Piece* get_piece() {
			return piece;
		}

		void visit() const override {
			cout << "Visit in : BB " << endl;
		}

};

int main() {
	Piece *test = new Piece("WHITE","Horse");
	BoardBlock *bb = new BoardBlock("Horse",test);

	test->visit();
	bb->visit();

	delete test;
	delete bb;
	
	return EXIT_SUCCESS;
}


