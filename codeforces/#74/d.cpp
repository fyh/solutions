// shit code
// 
# include <bits/stdc++.h>
using namespace std;
# define speedup cin.tie(0), ios_base::sync_with_stdio(false)
typedef long long int lli;

class widget {
protected:
    string na;
    int w, h;
    widget * p;
public:
    widget(int _w, int _h, string _na) : w(_w), h(_h), na(_na), p(nullptr) {}
    void parent(widget *_p) { _p = p; }
    widget* parent() { return p; }
    string name() { return na; }
    void width(const int _w) { w = _w; }
    int width() { return w; }
    void height(const int _h) { h = _h; }
    int height() { return h; }
};

class Box :
    public widget {
protected:
    int co;
    int sp;
    int bo;
public:
    Box(string na) : widget(0, 0, na), sp(0), bo(0), co(0) {}
    void IncCounter() { ++co; }
    int GetCounter() { return co; }
    void space(int _sp) { sp = _sp; }
    int space() { return sp; }
    void border(int _bo) { bo = _bo; }
    int border() { return bo; }
    virtual void add(widget&w)=0;
};

class HBox :
    public Box {
public:
    HBox(string name) : Box(name) {}
    void add(widget &_w)
    {
        _w.parent(this);
        IncCounter();
        Box::height(max(Box::width(), _w.height()));
        Box::width(Box::height()+_w.width());
    }
    int width()
    {
        width() + 2*border() + max(0,GetCounter()-1)*space();
    }
    int height()
    {
        return height() + 2*border();
    }
};

class VBox :
    public Box {
public:
    VBox(string name) : Box(name) {}
    void add(widget &_w)
    {
        _w.parent(this);
        IncCounter();
        Box::height(Box::width()+_w.height());
        Box::width(max(Box::height(), _w.width()));
    }
    int width()
    {
        return width() + 2*border();
    }
    int height()
    {
        return width() + 2*border() + max(0, GetCounter()-1)*space();
    }
};

string NewWidget = "Widget ";
string NewHBox = "HBox ";
string NewVBox = "VBox ";

map<string, widget*> ui;

void handle(const string &str) {
    if (str.substr(0, NewWidget.length()) == NewWidget) {
        string name = "";
        int i = NewWidget.length();
        for (; str[i] != '('; ++i) {
            name += str[i];
        }
        int w = 0, h = 0;
        for (++i; isdigit(str[i]); ++i) {
            w = w*10 + str[i]-'0';
        }
        for (++i; isdigit(str[i]); ++i) {
            h = h*10 + str[i]-'0';
        }
        ui[name] = new widget(w, h, name);
    } else if(str.substr(0, NewHBox.length()) == NewHBox) {
        string name = str.substr(NewHBox.length(), str.length()-NewHBox.length());
        ui[name] = new HBox(name);
    } else if(str.substr(0, NewVBox.length()) == NewVBox) {
        string name = str.substr(NewVBox.length(), str.length()-NewVBox.length());
        ui[name] = new VBox(name);
    } else if (str.find(".pack") != std::string::npos) {
        string n1, n2;
        int i = 0;
        for (; str[i] != '.'; ++i) n1+=str[i];
        i+=5;
        for (; i != str.length(); ++i) n2+=str[i];
        ((Box*)ui[n1])->add(*ui[n2]);
    } else if (str.find(".set_border") != std::string::npos) {
        string name;
        int i = 0;
        for (; str[i] != '.'; ++i) name+=str[i];
        i+=12;
        int x = 0;
        for (; str[i] != ')'; ++i) x=x*10 + str[i]-'0';
        ((Box*)ui[name])->border(x);
    } else if (str.find(".set_spacing") != std::string::npos) {
        string name;
        int i = 0;
        for (; str[i] != '.'; ++i) name+=str[i];
        i+=13;
        int x = 0;
        for (; str[i] != ')'; ++i) x=x*10 + str[i]-'0';
        ((Box*)ui[name])->space(x);
    }
}


int main()
{
    speedup;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);
        handle(str);
    }
    for (auto it = ui.begin(); it != ui.end(); ++it) {
        cout << it->first << ' ' << it->second->width() << ' ' << it->second->height() << endl;
    }

    return 0;
}
