#include "Dish.h"

inline string PFCKk::toString() {
	string res = name + " ";
	res += "Б: " + to_string(Proteins) + ", ";
	res += "Ж: " + to_string(Fat) + ", ";
	res += "У: " + to_string(Carbohydrates) + ", ";
	res += "ЭЦ: " + to_string(Energy_Kk) + " кКал.";
	return res;
}

inline bool PFCKk::getValue(string str, string ctrl, double& res) {
	int pos1 = str.find(ctrl);
	int pos2;
	if (pos1 >= 0) {
		pos2 = str.substr(pos1).find(" ");
		if (pos2 >= 0) {
			string str_val = str.substr(pos1 + ctrl.size(), pos2 - ctrl.size()).data();
			for (int k = 0; k < str_val.size(); ++k) {
				if (str_val[k] == '.') {
					str_val[k] = ',';
				}
			}
			res = stod(str_val);
			return true;
		}
	}
	return false;
}

inline double PFCKk::getValue(string str, string ctrl) {
	int pos1 = str.find(ctrl);
	int pos2;
	if (pos1 >= 0) {
		pos2 = str.substr(pos1).find(" ");
		if (pos2 >= 0) {
			string str_val = str.substr(pos1 + ctrl.size(), pos2 - ctrl.size()).data();
			for (int k = 0; k < str_val.size(); ++k) {
				if (str_val[k] == '.') {
					str_val[k] = ',';
				}
			}
			return stod(str_val);
		}
	}
}

inline void PFCKk::fromString(string str) {
	//"Картофель Б:2 Ж:0.4 У:16.3 KK:77"
	int pos1 = str.find(" ");

	if (pos1 > 0) {
		name = str.substr(0, pos1);
	}
	else {
		cout << "Неверный формат строки" << endl;
	}

	Proteins = getValue(str, "Б:");
	if (getValue(str, "Ж:", Fat) == false) {
		cout << "Error" << endl;
	}
	getValue(str, "У:", Carbohydrates);
	getValue(str, "KK:", Energy_Kk);
}
