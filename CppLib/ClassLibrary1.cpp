#include <math.h>

#include "shared.h"

using namespace System;

namespace ClassLibrary1 {
	public ref class Class1
	{
		public:
			static double Test(double val) {
				double arr[2];
				arr[0] = val;
				arr[1] = val * val;

				struct MainCalcResults ret = MainCalc(arr, 2 * val, 0.5 * val);
				return ret.H;
			}
	};
}
