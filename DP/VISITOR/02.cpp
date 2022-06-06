#include<iostream>
#include<string>

using namespace std;

class DocumentVisitor;
class DocumentPrinter;

class Document {
	private:
		string name;
	public:
		Document() {}
		~Document() {}

		Document(string name) : name{name} {}
		// virtual void add_to_list(const string& line) = 0;
		virtual void visit(DocumentVisitor* dv) = 0;
		
		string get_name() {
			return this->name;
		}
};


class Markdown : public Document {
	public:
		Markdown() {}
		~Markdown() {}

		Markdown(string name = "TestM") : Document{name} {}

		void visit(DocumentVisitor* dv) {
			dv->visit(this);
		}
};


class Html : public Document {
	public:
		Html() {}
		~Html() {}

		Html(string name = "Test") : Document{name} {}
		
		void visit(DocumentVisitor* dv) {
			dv->visit(this);
		}
};


class DocumentVisitor {
	public:
        	virtual void visit(Markdown* mk) = 0;
        	virtual void visit(Html* ht) = 0;
};


class DocumentPrinter : public DocumentVisitor {
        
	public:

		DocumentPrinter() {}
		~DocumentPrinter() {}

		void visit(Markdown* mk) {
                	std::cout << mk->get_name() << std::endl;
                	std::cout << "Mardown data : " << std::endl;
        	}

        	void visit(Html* ht) {
                	std::cout << ht->get_name() << std::endl;
                	std::cout << "HTML data : " << std::endl;
        	}

};

int main() {
	string test = "WOW";
	Document* d = new Html;
	d->visit(new DocumentPrinter);

	delete d;

	return EXIT_SUCCESS;
}
