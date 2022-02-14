#include "sqlite3.hpp"

#include <iostream>

int main() {
  sqlite::Database db("test.sqlite");

  sqlite::Connection conn;
  db.connect(conn).expect(SQLITE_OK);

  conn.execute("CREATE TABLE t (a)").expect(SQLITE_OK);

  sqlite::Statement insert;
  conn.prepare(insert, "INSERT INTO t VALUES (?), (?), (?)").expect(SQLITE_OK);

  insert.bind_all(42, "hello", 3.14).expect(SQLITE_OK);

  insert.step().expect(SQLITE_DONE);

  sqlite::Statement select;
  conn.prepare(select, "SELECT a FROM t").expect(SQLITE_OK);

  select.step().expect(SQLITE_ROW);
  std::cout << select.column_int(0) << std::endl;

  select.step().expect(SQLITE_ROW);
  std::cout << select.column_text(0) << std::endl;

  select.step().expect(SQLITE_ROW);
  std::cout << select.column_double(0) << std::endl;

  select.step().expect(SQLITE_DONE);

  select.reset().expect(SQLITE_OK);

  conn.execute("DROP TABLE t").expect(SQLITE_OK);

  return 0;
}
