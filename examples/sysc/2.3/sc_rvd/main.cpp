/*****************************************************************************

  Licensed to Accellera Systems Initiative Inc. (Accellera) under one or
  more contributor license agreements.  See the NOTICE file distributed
  with this work for additional information regarding copyright ownership.
  Accellera licenses this file to you under the Apache License, Version 2.0
  (the "License"); you may not use this file except in compliance with the
  License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
  implied.  See the License for the specific language governing
  permissions and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  main.cpp -- This example shows the use of the sc_rvd classes to demonstrate
              a communication channel that uses a ready-valid handshake.

  Original Author: Andy Goodrich, Forte Design Systems, Inc.

 *****************************************************************************/

// $Log: main.cpp,v $
// Revision 1.2  2011/08/15 16:43:24  acg
//  Torsten Maehne: changes to remove unused argument warnings.
//
// Revision 1.1  2011/06/14 21:25:39  acg
//  Andy Goodrich: moved examples from 2.2.1 potential release.
//
// Revision 1.1  2010/08/20 14:14:01  acg
//  Andy Goodrich: new example using a ready-valid handshake for communication.
//

#include "systemc.h"
#include <iomanip>
#include "sc_rvd.h"
#include <omp.h>
#include <iostream>
#include <thread>
using namespace std;

SC_MODULE(DUT0) {
	SC_CTOR(DUT0) {
		SC_METHOD(method1);
		sensitive << e1;
		dont_initialize();

		SC_METHOD(method2);
		sensitive << e2;
		dont_initialize();

		SC_METHOD(method3);
		sensitive << e3;
		dont_initialize();

		SC_METHOD(method4);
		sensitive << m_input4;
		dont_initialize();
	}

	void method1() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m1 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method2() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m2 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method3() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m3 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method4() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m4 = m_input4.read();
			m5 = m_input4.read();
		}
		e1.notify();
		e2.notify();
		e3.notify();
	}

	sc_in<sc_uint<32> > m_input4;
	sc_uint<32> m1, m2, m3, m4, m5;
	sc_event e1, e2, e3;
};
SC_MODULE(DUT1) {
	SC_CTOR(DUT1) {
		SC_METHOD(method1);
		sensitive << e1;
		dont_initialize();

		SC_METHOD(method2);
		sensitive << e2;
		dont_initialize();

		SC_METHOD(method3);
		sensitive << e3;
		dont_initialize();

		SC_METHOD(method4);
		sensitive << m_input4;
		dont_initialize();
	}

	void method1() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m1 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method2() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m2 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method3() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m3 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method4() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m4 = m_input4.read();
			m5 = m_input4.read();
		}
		e1.notify();
		e2.notify();
		e3.notify();
	}

	sc_in<sc_uint<32> > m_input4;
	sc_uint<32> m1, m2, m3, m4, m5;
	sc_event e1, e2, e3;
};
SC_MODULE(DUT2) {
	SC_CTOR(DUT2) {
		SC_METHOD(method1);
		sensitive << e1;
		dont_initialize();

		SC_METHOD(method2);
		sensitive << e2;
		dont_initialize();

		SC_METHOD(method3);
		sensitive << e3;
		dont_initialize();

		SC_METHOD(method4);
		sensitive << m_input4;
		dont_initialize();
	}

	void method1() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m1 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method2() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m2 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method3() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m3 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method4() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m4 = m_input4.read();
			m5 = m_input4.read();
		}
		e1.notify();
		e2.notify();
		e3.notify();
	}

	sc_in<sc_uint<32> > m_input4;
	sc_uint<32> m1, m2, m3, m4, m5;
	sc_event e1, e2, e3;
};
SC_MODULE(DUT3) {
	SC_CTOR(DUT3) {
		SC_METHOD(method1);
		sensitive << e1;
		dont_initialize();

		SC_METHOD(method2);
		sensitive << e2;
		dont_initialize();

		SC_METHOD(method3);
		sensitive << e3;
		dont_initialize();

		SC_METHOD(method4);
		sensitive << m_input4;
		dont_initialize();
	}

	void method1() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m1 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method2() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m2 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method3() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m3 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method4() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m4 = m_input4.read();
			m5 = m_input4.read();
		}
		e1.notify();
		e2.notify();
		e3.notify();
	}

	sc_in<sc_uint<32> > m_input4;
	sc_uint<32> m1, m2, m3, m4, m5;
	sc_event e1, e2, e3;
};
SC_MODULE(DUT4) {
	SC_CTOR(DUT4) {
		SC_METHOD(method1);
		sensitive << e1;
		dont_initialize();

		SC_METHOD(method2);
		sensitive << e2;
		dont_initialize();

		SC_METHOD(method3);
		sensitive << e3;
		dont_initialize();

		SC_METHOD(method4);
		sensitive << m_input4;
		dont_initialize();
	}

	void method1() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m1 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method2() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m2 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method3() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m3 = m_input4.read();
			m5 = m_input4.read();
		}
	}
	void method4() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m4 = m_input4.read();
			m5 = m_input4.read();
		}
		e1.notify();
		e2.notify();
		e3.notify();
	}

	sc_in<sc_uint<32> > m_input4;
	sc_uint<32> m1, m2, m3, m4, m5;
	sc_event e1, e2, e3;
};

SC_MODULE(T2) {
	SC_CTOR(T2) {
		SC_METHOD(method1);
		sensitive << e1;
		dont_initialize();

		SC_METHOD(method2);
		sensitive << e2;
		dont_initialize();

		SC_METHOD(method3);
		sensitive << e3;
		dont_initialize();

		SC_METHOD(method4);
		sensitive << m_input4;
		dont_initialize();

		SC_METHOD(method5);
		sensitive << e4;
		dont_initialize();

		SC_METHOD(method6);
		sensitive << e5;
		dont_initialize();


	}

	void method1() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m1 = m_input4.read();
			m5 = m_input4.read();
		}
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}
	void method2() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m2 = m_input4.read();
			m5 = m_input4.read();
		}
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}
	void method3() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m3 = m_input4.read();
			m5 = m_input4.read();
		}
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}
	void method4() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m4 = m_input4.read();
			m5 = m_input4.read();
		}
		e1.notify();
		e2.notify();
		e3.notify();
		e4.notify();
		e5.notify();
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}

	void method5() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m3 = m_input4.read();
			m5 = m_input4.read();
		}
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}

	void method6() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m3 = m_input4.read();
			m5 = m_input4.read();
		}
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}

	sc_in<sc_uint<32> > m_input4;
	sc_uint<32> m1, m2, m3, m4, m5;
	sc_event e1, e2, e3, e4, e5;
};

SC_MODULE(T3) {
	SC_CTOR(T3) {
		SC_METHOD(method1);
		sensitive << e1;
		dont_initialize();

		SC_METHOD(method2);
		sensitive << e2;
		dont_initialize();

		SC_METHOD(method3);
		sensitive << e3;
		dont_initialize();

		SC_METHOD(method4);
		sensitive << m_input4;
		dont_initialize();

		SC_METHOD(method5);
		sensitive << e4;
		dont_initialize();

		SC_METHOD(method6);
		sensitive << e5;
		dont_initialize();

		SC_METHOD(method7);
		sensitive << e6;
		dont_initialize();


	}

	void method1() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m1 = m_input4.read();
			m5 = m_input4.read();
		}
		e4.notify();
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}
	void method2() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m2 = m_input4.read();
			m5 = m_input4.read();
		}
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}
	void method3() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m3 = m_input4.read();
			m5 = m_input4.read();
		}
		e1.notify();
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}
	void method4() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m4 = m_input4.read();
			m5 = m_input4.read();
		}
		e2.notify();
		e3.notify();
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}

	void method5() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m3 = m_input4.read();
			m5 = m_input4.read();
		}
		e5.notify();
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}

	void method6() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m3 = m_input4.read();
			m5 = m_input4.read();
		}
		e6.notify();
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}

	void method7() {
		double prod = 1, sum = 1, sop = 1;
		for (int i = 1; i < 20000000; i++) {
			prod *= (double)i;
			sum += (double)i;
			sop *= (prod * sum);
			sop = ((prod + sum + sop) * sop * sop) / sum;
			m3 = m_input4.read();
			m5 = m_input4.read();
		}
		//cout << "thread num in method : " << omp_get_thread_num() << endl;
	}

	sc_in<sc_uint<32> > m_input4;

	sc_uint<32> m1, m2, m3, m4, m5;
	sc_event e1, e2, e3, e4, e5, e6;
};

SC_MODULE(TB) {
	SC_CTOR(TB) {
		SC_METHOD(Method1);
		SC_METHOD(Method2);
		SC_METHOD(Method3);
	}

	void Method1() {

			m_output1.write(1);
	}

	void Method2() {

		m_output2.write(1);
	}

	void Method3() {

		m_output3.write(1);
	}
	sc_out<sc_uint<32> >m_output1;
	sc_out<sc_uint<32> >m_output2;
	sc_out<sc_uint<32> >m_output3;
};


int sc_main(int , char* [])
{

	DUT0 d0("d0");
	DUT1 d1("d1");
	DUT2 d2("d2");
	DUT3 d3("d3");
	DUT4 d4("d4");

	sc_signal<sc_uint<32> > sig0;
	sc_signal<sc_uint<32> > sig1;
	sc_signal<sc_uint<32> > sig2;

	TB tb("tb");
	d0.m_input4(sig0);
	d1.m_input4(sig0);
	d2.m_input4(sig0);
	d3.m_input4(sig0);
	d4.m_input4(sig0);


	tb.m_output1(sig0);
	tb.m_output2(sig1); 
	tb.m_output3(sig2);

	T2 t2("t2");
	T3 t3("t3");

	t2.m_input4(sig1);
	t3.m_input4(sig2);

	unsigned concurentThreadsSupported = std::thread::hardware_concurrency();
	cout << "Number of core : " << omp_get_max_threads() << endl;

	omp_set_num_threads(omp_get_max_threads() / 2);

	double start_time, end_time;
	start_time = omp_get_wtime();

    sc_start();
	end_time = omp_get_wtime();
    cout << "Program completed" << endl;
	cout << "Done, Run time : " << end_time - start_time << endl;
    return 0;
}
