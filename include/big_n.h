#include <vector>
#include <iostream>

#ifndef BIG_N_H
#define BIG_N_H 

class BigInt;
class BigFra;

enum CompareNat : int {equal, rhsIsBigger, lhsIsBigger};

class BigNat{

protected:	
	std::vector<int> digits; // Digits store in reversed order

public:
	friend std::ostream& operator<< (std::ostream &stream, const BigNat &num);
	friend std::istream& operator>> (std::istream &stream, BigNat &num);
	
	//=====MODULES=====
	//Author: Alex Kosh 7301
	
	friend int COM_NN_D(BigNat lhs, BigNat rhs); 				 
	friend bool NZER_N_B(BigNat lhs); 							 
	friend BigNat ADD_1N_N(BigNat lhs); 						 
	friend BigNat ADD_NN_N(BigNat lhs, BigNat rhs); 			 
	friend BigNat SUB_NN_N(BigNat lhs, BigNat rhs); 			 
	friend BigNat MUL_ND_N(BigNat lhs, int mul); 				 
	friend BigNat MUL_Nk_N(BigNat lhs, int k); 				 
	friend BigNat MUL_NN_N(BigNat lhs, BigNat rhs);	// not optimal
	friend BigNat SUB_NDN_N(BigNat lhs, int k, BigNat rhs);	// useless?
	friend BigNat DIV_NN_Dk(BigNat lhs, BigNat rhs); 
	friend BigNat DIV_NN_N(BigNat lhs, BigNat rhs); 			 
	friend BigNat MOD_NN_N(BigNat lhs, BigNat rhs);	// may be not optimal?
	friend BigNat GCD_NN_N(BigNat lhs, BigNat rhs);				 
	friend BigNat LCM_NN_N(BigNat lhs, BigNat rhs);			 
	
	//==Friends for BigInt and BigFra==
	friend BigInt TRANS_N_Z(BigNat lhs);
	friend BigNat TRANS_Z_N(BigInt lhs);
	friend BigFra TRANS_Z_Q(BigInt lhs);
	
	//======================
	//==EXTRA MODULES==
	friend BigNat FACTOR_N_N(BigNat lhs);
	friend BigNat FIB_N_N(BigNat lhs);
	
	
	//======Operators support======
	BigNat operator++(int num);
	BigNat operator+(const BigNat &rhs);
	BigNat operator-(const BigNat &rhs);
	BigNat operator*(const BigNat &rhs);
	BigNat operator*(const int &rhs);
	BigNat operator/(const BigNat &rhs);
	BigNat operator%(const BigNat &rhs);
	
	bool operator<(const BigNat &rhs);
	bool operator>(const BigNat &rhs);
	bool operator<=(const BigNat &rhs); 
	bool operator>=(const BigNat &rhs);
	bool operator==(const BigNat &rhs);
	
	//=============================
	
	BigNat(std::string str);
	BigNat();
	BigNat(BigInt num);
	void remove_leading_zeros();
};


#endif
