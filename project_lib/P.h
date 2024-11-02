//Efimova
struct P {

    vector<Q> a;

};

P operator-(const P& p1);
P operator+(const P& p1, const P& p2);
P operator-(const P& p1, const P& p2);
P operator*(const P& p, const Q& q);
P MUL_PQ_P(const P& p, const Q& q);
P ADD_PP_P(const P& p1, const P& p2);
P SUB_PP_P(const P& p1, const P& p2);

//Efimova
