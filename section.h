#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

class Section {
  public:
	Section(const std::string f) {
	  parse(f, " ");
	}

	void parse(const std::string f, const std::string delim) {

	  std::ifstream infile(f);

	  std::string line;
	  while (std::getline(infile, line)) {
		size_t pos = 0;

		std::vector<std::string> tokens = split(line, ' ');

		if (tokens[0] == "C") {
		  std::cout << "Creando: " << tokens[1] << ' ' << tokens[2] << '\n';
		  alumnos.insert({tokens[1], std::stoi(tokens[2])});

		} else if (tokens[0] == "L") {
		  if (tokens[1] == "All") {
			std::cout << "Print todos los alumnos:\n";
			for (auto &m : alumnos) {
			  std::cout << "  " << m.first << ' ' << m.second << '\n'; 
			}
		  } else {
			auto val = alumnos.at(tokens[1]);
			std::cout << "Info: " << tokens[1] << ' ' << val << '\n';
		  }

		} else if (tokens[0] == "D") {
		  std::cout << "Delete: " << tokens[1] << '\n';
		  alumnos.erase(tokens[1]);
		}
		tokens.clear();
	  }

	}

	std::vector<std::string> split(std::string str, char delimiter) {
	  std::vector<std::string> internal;
	  std::stringstream ss(str);
	  std::string tok;

	  while(getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	  }

	  return internal;
	}

  private:
	std::map<std::string, int> alumnos;
};
