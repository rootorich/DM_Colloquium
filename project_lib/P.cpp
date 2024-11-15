#include <regex>
#include <vector>
#include <string>

#include "P.h"

using namespace std::rel_ops;

P::P() {} 


/*
 * Efimova
 * P-1
*/
P operator+(const P& p1, const P& p2) {
  P result = (p1.a.size() >= p2.a.size()) ? p1 : p2;
  P min = (p1.a.size() < p2.a.size()) ? p1 : p2;

  for (size_t i = 0; i < min.a.size(); ++i) {
    result.a[i] = result.a[i] + min.a[i];
  }

  CLR_P_V(result);

  return result;
}

void operator+=(P& p1, const P& p2) {
  p1 = p1 + p2;
}

P ADD_PP_P(const P& p1, const P& p2) {
  return p1 + p2;
}

/*
 * P-2
*/
P operator-(const P& p1) {
  P p = p1;

  for (auto & a : p.a){
    a = -a;
  }

  return p;
}

P operator-(const P& p1, const P& p2) {
  return p1 + (-p2);
}

P SUB_PP_P(const P& p1, const P& p2) {
  return p1 - p2;
}

/*
 * P-3
*/
P operator*(const P& p, const Q& q) {
  P result;

  for (const auto & a : p.a){
    result.a.push_back(a * q);
  }

  CLR_P_V(result);

  return result;
}

P operator*(const P& p, const uint8_t digit) {
  return p * Q(digit);
}

P MUL_PQ_P(const P& p, const Q& q) {
  return p * q;
}

/*
 * End Efimova
*/


/*
* Savranraskii Danila
* P-4
*/
P operator<<(const P &p, const uint32_t k) {
  P result = p;

  Q zero = Q(0);
  result.a.insert(result.a.begin(), k, zero);

  return result;
}

P MUL_Pxk_P(const P &p, const uint32_t k) {
  return p << k;
}

/*
 * P-5
*/
Q LED_P_Q(const P &p) {
  return p.a.back();
}

/*
 * P-6
*/
N DEG_P_N(const P &p) {
  return N(std::to_string(p.a.size() - 1));
}

/*
 * P-7
*/
Q FAC_P_Q(const P &p) {
  N GCF = N(1); // НОД
  N LCM = N(1); // НОК

  size_t i = 0;
  // Находим первую значащую цифру и приписываем ей НОК и НОД
  while (i < p.a.size()) {
    if (p.a[i].z != 0) {
      GCF = p.a[i].z;
      LCM = p.a[i].n;
      ++i;
      break;
    }
    ++i;
  }
  // Учитываем оставшиеся числа
  while (i < p.a.size()) {
    if (p.a[i].z != 0) {
      GCF = GCF_NN_N(GCF, p.a[i].z); // НОД всех числителей
      LCM = LCM_NN_N(LCM, p.a[i].n); // НОК всех знаменателей
    }
    ++i;
  }
  return Q(TRANS_N_Z(GCF), LCM);
}

/*
 * End Savranraskii Danila
*/


/*
 * Efimova
 * P-8
*/
P operator*(const P& p1, const P& p2){
  P product;
  product.a.emplace_back(0);

  if((p1.a.size() == 1 && p1.a[0].z == 0 )||
    (p2.a.size() == 1 && p2.a[0].z == 0 )){
    return product;
  }

  for (size_t i = 0; i < p2.a.size(); ++i) {
    if(p2.a[i].z != 0){
      product += (p1 *p2.a[i]) << i;
    }
  }

  return product;
}

P MUL_PP_P(const P& p1, const P& p2) {
  return p1 * p2;
}

/*
 * End Efimova
*/

/*
 * Kate
 * P-9
*/
P operator/(const P& p1, const P& p2) {
  if (DEG_P_N(p1) < DEG_P_N(p2)) {
    return P("0");
  }

  P quotient;
  P remainder = p1;

  quotient.a.resize(p1.a.size() - p2.a.size() + 1);

  for (size_t i = p1.a.size() - 1; i >= (p2.a.size()) - 1; --i) {
    CLR_P_V(remainder);
    if (remainder.a.size() <= i) continue; // не работает, пока нет удаление незначащих нулей
    size_t shift = i + 1 - p2.a.size();
    Q new_q = remainder.a[i] / p2.a.back();
    
    CLR_P_V(remainder);
    remainder = remainder - (p2 << shift) * new_q; // не работает, пока не удаляются незначащие нули

    quotient.a[shift] = new_q;
  }

  return quotient;
}

P DIV_PP_P(const P& p1, const P& p2) { return p1 / p2; }

/*
 * P-10
*/
P operator%(const P& p1, const P& p2) {
  return p1 - ((p1 / p2) * p2);
}

P MOD_PP_P(const P& p1, const P& p2) {
  return p1 % p2;
}


/*
 * End Kate
*/


/*
 * Masha
 * P-11
*/
P GCF_PP_P(const P& p1, const P& p2) {
  P t1 = p1;
  P t2 = p2;

  while (t1 != 0) {
    if (t1 < t2) {
      std::swap(t1, t2);
    }
    t1 = t1 % t2;
  }

  return t2;
}

/*
 P-12
*/
P DER_P_P(const P& p) {
  P res;

  for (size_t i = 1; i < p.a.size(); i++) {
    res.a.emplace_back(p.a[i] * Q(std::to_string(i), "1"));
  }

  if (res.a.size() == 0)
      res = P("0");

  return res;
}


/*
 * P-Dop-2
*/
void CLR_P_V(P& num) {
  while (num.a.size() > 1 && num.a.back() == 0) {
    num.a.pop_back();
  }
}
/*
 * End Masha
*/


/*
 * P-Dop-1.1
*/
bool operator<(const P& p1, const P& p2) {
  if (DEG_P_N(p1) < DEG_P_N(p2)) {
    return true;
  } else if (DEG_P_N(p1) > DEG_P_N(p2)) {
    return false;
  } else {
    return (p1.a.back() < p2.a.back());
  }
}

/*
 * P-Dop-1.2
*/
bool operator==(const P& p1, const P& p2) {
  if (DEG_P_N(p1) == DEG_P_N(p2)) {
    size_t i = p1.a.size() - 1;

    while (true) {
      if (p1.a[i] != p2.a[i]) {
        return false;
      }
      if (i == 0) {
        break;
      }

      --i;
    }

    return true;
  } else {
    return false;
  }
}

bool operator==(const P& p, const uint8_t digit) {
  if (DEG_P_N(p) == 0) {
    if (p.a.back() == digit) {
      return true;
    }
  }

  return false;
}


/* Masha
 * P-Dop-1.1
*/
P::P(const std::string& str) {
    std::regex pattern(R"(([+-]? ?\d*(/\d+)?)x\^?(\d*))");
    std::smatch matches;

    auto begin = std::sregex_iterator(str.begin(), str.end(), pattern);
    auto end = std::sregex_iterator();

    for (auto it = begin; it != end; ++it) {
        std::string n = it->str(1);
        if (!isdigit(n[n.size() - 1])) {
            n += "1";
        }
        if (n[1] == ' ')
            n = n[0] + n.substr(2, n.size());
        if (n[0] != '+' && n[0] != '-')
            n = '+' + n;
        std::string b = "1";
        if (n.find('/') != std::string::npos) {
            n = n.substr(0, n.find('/'));
            b = it->str(2).substr(it->str(2).find('/')+1, it->str(2).size());
        }

        Q q(n, b);
        int exp = 1;
        if (it->str(3) != "")
            exp = stoi(it->str(3));

        if (a.size() < exp+1)
            a.resize(exp+1, Q(0));
        a[exp] = q;
    }

    int minus = -1, plus = -1;
    if (str.rfind('-') != std::string::npos) {
        minus = str.rfind('-');
    }
    if (str.rfind('+') != std::string::npos) {
        plus = str.rfind('+');
    }

    int ind = (minus > plus) ? minus : plus;
    if (a.size() == 0) {
        a.resize(1);
        ind = 0;    // если было введено только число
    }

    if (ind != -1 && str.substr(ind).find('x') == std::string::npos) {
        std::string n = str.substr(ind);
        if (n[1] == ' ')
          n = n[0] + n.substr(2, n.size());

        std::string e = n;
        std::string b = "1";
        if (n.find('/') != std::string::npos) {
            e = n.substr(0, n.find('/'));
            b = n.substr(n.find('/')+1, n.size());
        }
        a[0] = Q(n);
    }
}

/*
 * P-Dop-1.2
*/
std::string P::to_str() {
    std::string res;
    for (int i = a.size()-1; i > 1; --i) {
        if (a[i] != 0) {
            if (a[i] != 1 && a[i] != -1)
                res += a[i].to_str();
            else
                res += a[i].to_str()[0];
            res += "x^" + std::to_string(i) + " ";
        }
    }
    if (a.size() > 1 && a[1] != 0) {
        if (a[1] != 1 && a[1] != -1)
            res += a[1].to_str();
        else
            res += a[1].to_str()[0];
        res += "x ";
    }
    if (a[0] != 0 || a.size() == 1) {
        res += a[0].to_str();
    }
    if (res[0] == '+')
      res = res.substr(2); /* delete sign '+' */
    return res;
}

/* 
  End Masha
*/