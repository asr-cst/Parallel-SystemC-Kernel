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
	sc_out<sc_uint<32> > m_output1;
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
	sc_in<sc_uint<32> > m_input1;
	sc_in<sc_uint<32> > m_input2;

	sc_uint<32> m1, m2, m3, m4, m5;
	sc_event e1, e2, e3, e4, e5, e6;
};

SC_MODULE(TB) {
	SC_CTOR(TB) {
		SC_THREAD(thread1);
		SC_THREAD(thread2);
		SC_THREAD(thread3);
	}

	void thread1() {
		for (int i = 0; i < 2; i++) {
			wait(1, SC_NS);
			m_output1.write(1 + i);
			wait(10, SC_NS);
		}
	}

	void thread2() {
		for (int i = 0; i < 2; i++) {
			wait(1, SC_NS);
			//m_output2.write(1 + i);
			wait(10, SC_NS);
		}
	}

	void thread3() {
		for (int i = 0; i < 2; i++) {
			wait(1, SC_NS);
			//m_output2.write(1 + i);
			wait(10, SC_NS);
		}
	}
	sc_out<sc_uint<32> >m_output1;
	//sc_out<sc_uint<32> >m_output2;
};

SC_MODULE(TB1) {
	SC_CTOR(TB1) {
		SC_THREAD(thread1);
		SC_THREAD(thread2);
		SC_THREAD(thread3);
	}

	void thread1() {
		for (int i = 0; i < 2; i++) {
			wait(1, SC_NS);
			//m_output1.write(1 + i);
			wait(10, SC_NS);
		}
	}

	void thread2() {
		for (int i = 0; i < 2; i++) {
			wait(1, SC_NS);
			//m_output2.write(1 + i);
			wait(10, SC_NS);
		}
	}

	void thread3() {
		for (int i = 0; i < 2; i++) {
			wait(1, SC_NS);
			//m_output2.write(1 + i);
			wait(10, SC_NS);
		}
	}
	//sc_out<sc_uint<32> >m_output1;
	//sc_out<sc_uint<32> >m_output2;
};

//SC_MODULE(DUT)
//{
//    SC_CTOR(DUT)
//    {
//        SC_CTHREAD(thread,m_clk.pos());
//        reset_signal_is(m_reset, false);
//    }
//    void thread()
//    {
//        sc_uint<8> data[10];
//
//        m_input.reset();
//        m_output.reset();
//	wait();
//	for (;;)
//	{
//	    for ( int outer_i = 0; outer_i < 10; outer_i++ )
//	    {
//		for ( int inner_i = 0; inner_i < outer_i; inner_i++ )
//		{
//		    data[inner_i] = m_input.read();
//		    cout << "         " << std::setw(3) << data[inner_i] 
//			 << "          " << sc_time_stamp() << endl;
//		}
//		for ( int inner_i = 0; inner_i < outer_i; inner_i++ )
//		{
//		    m_output = data[inner_i];
//		}
//	    }
//	}
//    }
//    sc_in<bool>              m_clk;
//    sc_rvd<sc_uint<8> >::in  m_input;
//    sc_rvd<sc_uint<8> >::out m_output;
//    sc_in<bool>              m_reset;
//};
//
//SC_MODULE(TB)
//{
//    SC_CTOR(TB)
//    {
//        SC_CTHREAD(consumer,m_clk.pos());
//        reset_signal_is(m_reset, false);
//        SC_CTHREAD(producer,m_clk.pos());
//        reset_signal_is(m_reset, false);
//    }
//
//    void consumer()
//    {
//	sc_uint<8> data;
//
//        m_from_dut.reset();
//	wait();
//
//        for ( int i = 0; i < 40; i++ )
//        {
//	    data = m_from_dut.read();
//	    cout << "               " << std::setw(3) << data << "    "
//	         << sc_time_stamp() << endl;
//        }
//	sc_stop();
//    }
//
//    void producer()
//    {
//	sc_uint<8> data;
//
//        m_to_dut.reset();
//	wait();
//        for ( int i = 0;; i++ )
//        {
//	    cout << "  " << std::setw(3) << i << "                 "
//	         << sc_time_stamp() << endl;
//	    data = i;
//	    m_to_dut = data;
//	    if ( i && (i % 6 == 0) ) wait(i);
//        }
//    }
//
//    sc_in<bool>              m_clk;
//    sc_rvd<sc_uint<8> >::in  m_from_dut;
//    sc_in<bool>              m_reset;
//    sc_rvd<sc_uint<8> >::out m_to_dut;
//};

int sc_main(int , char* [])
{
    /*sc_clock            clock;
    DUT                 dut("dut");
    sc_rvd<sc_uint<8> > dut_to_tb;
    sc_signal<bool>     reset;
    TB                  tb("tb");
    sc_rvd<sc_uint<8> > tb_to_dut;

    dut.m_clk(clock);
    dut.m_reset(reset);
    dut.m_input(tb_to_dut);
    dut.m_output(dut_to_tb);

    tb.m_clk(clock);
    tb.m_reset(reset);
    tb.m_from_dut(dut_to_tb);
    tb.m_to_dut(tb_to_dut);*/

	DUT0 d0("d0");
	DUT1 d1("d1");
	DUT2 d2("d2");
	DUT3 d3("d3");
	DUT4 d4("d4");

	sc_signal<sc_uint<32> > sig0;
	TB tb("tb");
	tb.m_output1(sig0);
	d0.m_input4(sig0);
	d1.m_input4(sig0);
	d2.m_input4(sig0);
	d3.m_input4(sig0);
	d4.m_input4(sig0);

	/*T2 t2("t2");
	T3 t3("t3");

	TB tb("tb");
	TB1 tb1("tb1");

	sc_signal<sc_uint<32> > sig0;
	sc_signal<sc_uint<32> > sig1;
	sc_signal<sc_uint<32> > sig2;

	t2.m_input4(sig0);
	t3.m_input4(sig0);

	t2.m_output1(sig1);
	t3.m_input1(sig1);

	tb.m_output1(sig0);
	tb.m_output2(sig2);
	t3.m_input2(sig2);*/

	unsigned concurentThreadsSupported = std::thread::hardware_concurrency();
	cout << "no of core " << concurentThreadsSupported << endl;

	double start_time, end_time;
	start_time = omp_get_wtime();

    //cout << "producer dut consumer " << endl;
    //reset = false;
    //sc_start(1, SC_NS);
    //reset = true;
    sc_start();
	end_time = omp_get_wtime();
    cout << "Program completed" << endl;
	cout << "Done, Run time : " << end_time - start_time << endl;
    return 0;
}
