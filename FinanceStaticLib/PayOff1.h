#pragma once



	class PayOff
	{
	public:
		enum OptionType { Call, Put, Digital, DoubleDigital };
		PayOff(double Strike_, double UpperStrike_, OptionType TheOptionsType_);
		double operator()(double Spot) const;


	private:
		double Strike;
		double UpperStrike;
		OptionType TheOptionsType;
	};


