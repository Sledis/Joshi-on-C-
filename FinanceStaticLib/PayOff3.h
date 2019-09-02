#pragma once
class PayOff
{
public:
	PayOff() {};

	virtual double operator()(double Spot) const = 0;
	virtual ~PayOff() {};
	virtual PayOff* clone() const = 0;

private:

};

class PayOffPut : public PayOff {
public:
	PayOffPut(double Strike_);

	virtual double operator()(double Spot) const;
	virtual ~PayOffPut() {};
	virtual PayOff* clone() const;

private:
	double Strike;
};

class PayOffCall : public PayOff {
public:
	PayOffCall(double Strike_);

	virtual double operator()(double Spot) const;
	virtual ~PayOffCall() {};
	virtual PayOff* clone() const;

private:
	double Strike;
};

