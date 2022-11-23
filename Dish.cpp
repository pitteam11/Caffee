#include "Dish.h"

string PFCKk::toString() {
	string res = name + " ";
	res += "Б: " + to_string(Proteins) + ", ";
	res += "Ж: " + to_string(Fat) + ", ";
	res += "У: " + to_string(Carbohydrates) + ", ";
	res += "ЭЦ: " + to_string(Energy_Kk) + " кКал.";
	return res;
}


bool PFCKk::getValue(string str, string ctrl, double& res) {
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

double PFCKk::getValue(string str, string ctrl) {
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

bool PFCKk::fromStringFormat2(string str) {
	//"Амарант;13,60;7,00;69,00;371,00;"	
	int pos[5]; 
	int cnt = 0;
	for (int k = 0; (k < str.size() && (cnt <= 5)); ++k) {
		if (str[k] == ';') {
			pos[cnt++] = k;
		}
	}
	if (pos[0] < 0 || pos[1] < 0 || pos[2] < 0 || pos[3] < 0 || pos[4] < 0) {
		return false;
	}

	name = str.substr(0, pos[0]);
	Proteins      = stod(str.substr(pos[0]+1, pos[1] - pos[0]-1));
	Fat           = stod(str.substr(pos[1]+1, pos[2] - pos[1]-1));
	Carbohydrates = stod(str.substr(pos[2]+1, pos[3] - pos[2]-1));
	Energy_Kk     = stod(str.substr(pos[3]+1, pos[4] - pos[3]-1));

	if (Proteins < 0 || Proteins > 100 ||
		Fat < 0 || Fat > 100 ||
		Carbohydrates < 0 || Carbohydrates > 100)
		return false;
		
	return true;
}

bool PFCKk::fromStringFormat1(string str) {
	//"Картофель Б:2 Ж:0.4 У:16.3 KK:77"
	int pos1 = str.find(" ");
	if (pos1 > 0) {
		name = str.substr(0, pos1);
	}
	else {
		return false;
	}

	Proteins = getValue(str, "Б:");
	if (getValue(str, "Ж:", Fat) == false) {
		cout << "Error" << endl; // return false;
	}
	getValue(str, "У:", Carbohydrates);
	getValue(str, "KK:", Energy_Kk);
	return true;
}

void PFCKk::fromString(string str) {
	if (fromStringFormat2(str))
		return;
	if (fromStringFormat1(str))
		return;
}
