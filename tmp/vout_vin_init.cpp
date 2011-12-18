#include <ostream>
#include <istream>
#include <ext/stdio_sync_filebuf.h>
class vostream : public std::ostream{
	public:
		int times;
		vostream(std::streambuf *sb): std::ostream(sb), times(0){
		}
		const vostream& operator<< (int& num){
			this->std::ostream::operator<<(num);
			++times;
			return *this;
		}
};

__gnu_cxx::stdio_sync_filebuf<char> buf_vout_sync(stdout);
__gnu_cxx::stdio_sync_filebuf<char> buf_vin_sync(stdin);
vostream vout(&buf_vout_sync);
std::istream vin(&buf_vin_sync);


int main(){
	int test;
	vin >> test;
	vout << test << std::endl;
	vout << test;
	vout << test;
	vout << test;
	vout << vout.times;
}
