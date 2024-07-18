// Wells Fargo
#include <sstream>
#include "Matrix.h"
#include "comparer_builder.h"

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

struct MyStruct {
	MyStruct(int x1, int x2, const std::string& x3)
		: x1(x1), x2(x2), x3(x3)
	{ }
	int x1;
	int get_x2() const { return x2; }
	const std::string& get_x3() const { return x3; }
private:
	int x2;
	std::string x3;
};

int test_comparer_builder()
{
	{
		MyStruct a{ 1, 2, "a" }, b{ 2, 1, "b" };
		comparer_builder<MyStruct> cb;
		cb.by(&MyStruct::x1);
		assert(cb(a, b));
		assert(!cb(b, a));
		assert(!cb(a, a));
	}
	{
		std::vector<MyStruct> v = {
			{1, 2, "a"},
			{2, 1, "b"},
			{1, 1, "c"}
		};

		std::sort(v.begin(), v.end(),
			comparer_builder<MyStruct>().by(&MyStruct::x1).by(&MyStruct::get_x2));
		assert(v[0].get_x3() == "c");
		assert(v[1].get_x3() == "a");
		assert(v[2].get_x3() == "b");
	}
	{
		std::vector<MyStruct> v = {
			{1, 2, "b"},
			{2, 1, "b"},
			{3, 1, "a"}
		};

		std::sort(v.begin(), v.end(),
			comparer_builder<MyStruct>().by(&MyStruct::get_x3).by(&MyStruct::get_x2));
		assert(v[0].x1 == 3);
		assert(v[1].x1 == 2);
		assert(v[2].x1 == 1);
	}

	return 0;
}



int main()
{
	matrix_test();
    test_comparer_builder();

	return 0;
}
