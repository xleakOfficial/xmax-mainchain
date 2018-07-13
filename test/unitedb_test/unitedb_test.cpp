#define BOOST_TEST_MODULE pro_test

#include <boost/test/included/unit_test.hpp>

#include <unitedb/unitedb.hpp>

using namespace unitedb;

enum EOBJType
{
	OBJType_test = 0,
};

DBOBJECT_CLASS(TestDBObject, OBJType_test)
{		
public:
	template<typename C, typename T>
	TestDBObject( C&& c, DBAlloc<T>)
	{
		c(*this);
	}
	TestDBObject() = default;

	int xx = 5;
};

struct by_id;
typedef DBTableDeclaration<
	TestDBObject,
	boost::multi_index::indexed_by<
	INDEXED_BY_OBJECT_ID
	>
> TestIdx;

typedef DBTable<TestIdx> TestTable;


BOOST_AUTO_TEST_SUITE(unitedb_suite)

BOOST_AUTO_TEST_CASE(db_develop_test)
{
	unitedb::Database db(fs::current_path(), 1024 * 1024);//, unitedb::Database::Discard);//

	db.InitTable<TestTable>();

	auto tbl = db.GetTable<TestTable>();

	auto xx = tbl->NewObject([&](TestTable::ObjectType& a)
	{
		a.xx = 1024;
	});

	auto xxf = tbl->FindObject<ByObjectID>((ObjectIDCode)1);


	tbl->UpdateObject(xx, [&](TestTable::ObjectType& a)
	{
		a.xx = 2048;
	});

	const auto& ids = tbl->GetOrderIndex<ByObjectID>();
	std::vector<TestDBObject> objs;
	for (auto it : ids)
	{
		objs.push_back(it);
	}

	//tbl->DeleteObject(xxf);

	//TestIdx tidxs(db.GetSegmentManager());

	//TestIdx::index<ByID>::type& tp = tidxs.get<ByID>();

	//tidxs.emplace([&](TestTable::ObjectType& a)
	//{
	//}, TestTable::AllocType(db.GetSegmentManager()));

	//auto& idx = tidxs.get<ByID>();

	//auto ff = idx.find(0);

	//idx.iterator_to(*ff);

	//tidxs.modify( ff,[&](TestTable::ObjectType& a)
	//{
	//});

	//int ss = 0;
	//tidxs.get<0>().emplace(TestDBObject());
}

BOOST_AUTO_TEST_SUITE_END()