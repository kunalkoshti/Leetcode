class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) { sheet.resize(rows + 1, vector<int>(26, 0)); }
    pair<int, int> get_cell(string cell) {
        int col = cell[0] - 'A';
        int row = 0;
        int mul = 1;
        for (int i = cell.size() - 1; i > 0; i--) {
            row += (cell[i] - '0') * mul;
            mul *= 10;
        }
        return {col, row};
    }
    void setCell(string cell, int value) {
        pair<int, int> p = get_cell(cell);
        sheet[p.second][p.first] = value;
    }

    void resetCell(string cell) {
        pair<int, int> p = get_cell(cell);
        sheet[p.second][p.first] = 0;
    }
    bool is_num(char c) {
        if ((c - '0') >= 0 && (c - '0') < 10)
            return true;
        return false;
    }

    int get_num(string s) {
        int res = 0;
        int mul = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            res += (s[i] - '0') * mul;
            mul *= 10;
        }
        return res;
    }

    int param(string s) {
        if (!is_num(s[0])) {
            pair<int, int> p = get_cell(s);
            return sheet[p.second][p.first];
        }
        return get_num(s);
    }

    int getValue(string formula) {
        string val1 = "", val2 = "";
        int itr = 1;
        while (formula[itr] != '+') {
            val1 += formula[itr];
            itr++;
        }
        itr++;
        while (itr < formula.length()) {
            val2 += formula[itr];
            itr++;
        }
        return param(val1) + param(val2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */