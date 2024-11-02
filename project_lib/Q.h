//Efimova
struct Q {

    Z z;
    N n;
};

Q& Q:: operator=(const Z& z1);
Q& operator+(const Q& q1, const Q& q2);
Q TRANS_Z_Q(const Z& z);
Z TRANS_Q_Z(const Q& ratio);
Q ADD_QQ_Q(const Q& q1, const Q& q2);
Q RED_Q_Q(const Q& ratio);
bool INT_Q_B(const Q& ratio);

//Efimova

