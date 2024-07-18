// Wells Fargo
#include <sstream>
#include "Matrix.h"

using namespace WF2;

int matrix_test()
{
    {
        Matrix m(2,3,4);
        assert(m.to_string() == "[[4, 4, 4], [4, 4, 4]]");
    }
    {
        std::ofstream ofs("/tmp/matrix.params", std::ios_base::trunc);
        assert(ofs.is_open());
        ofs << 2 << " " << 3 << " " << 4;
        ofs.close();
        Matrix m("/tmp/matrix.params");
        assert(m.to_string() == "[[4, 4, 4], [4, 4, 4]]");
    }

	return 0;
}

int main()
{
	matrix_test();

	return 0;
}
