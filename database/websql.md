# Web SQL
## 创建表
```javascript
  var db = openDatabase('wroxdb', '1.0', 'Test DB', '2*1024*1024');

            // Sotre form data to local variables
            var name = document.userRegistration.usr_name.value;
            var email = document.userRegistration.emailId.value;
            var password = document.userRegistration.password.value;
            var contact = document.userRegistration.contact.value;
            var address = document.userRegistration.address.value;

            db.transaction(function(tx){
              tx.executeSql('CREATE TABLE IF NOT EXISTS USERDETALL (id INTEGER NOT NULL PRIMARY KEY, name, email, password, contact, address)');

              //Insert row to database
              tx.executeSql(
                "INSERT INTO USERDETALL VALUES (NULL, ?, ?, ?, ?, ?)",[name, email, password, contact, address]
              );
            });
```
## 查询
```javascript
var db = openDatabase('wroxdb', '1.0', 'Test DB', 2*1024*1024);
      $(document).ready(function(){
        db.transaction(function (tx) {
            tx.executeSql("SELECT * FROM USERDETALL", [] , function(tx, results) {
              var len = results.rows.length;
              var msg = "<table class='dbTabble'> <tr class='theader'><td>ID</td><td>Name</td><td>Email ID</td><td>Password</td><td> Contact </td><td>Address</td></tr>";
              alert(len);
              for (i = 0; i < len; i++){
                var row=results.rows.item(i);
                msg += "<tr><td>" + row['id'] + "</td><td>";
                msg += row['name'] + "</td><td>";
                msg += row['email'] + "</td><td>";
                msg += row['password'] + "</td><td>";
                msg += row['contact'] + "</td><td>";
                msg += row['address'] + "</td><td></tr>";
              }
              msg +="<table>";
              document.getElementById("status").innerHTML = msg;
            });
          }
        );
      });
```
