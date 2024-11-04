#include <iostream>
#include <absl/container/flat_hash_set.h>
int main()
{
	absl::flat_hash_set<int> set;
	set.insert( 1 );
	set.insert( 2 );
	set.insert( 3 );

	std::cout << set.size() << std::endl;
	system( "pause" );
	return 0;
}