PASSWORD CHECK ICIN: SELECT * FROM USERS WHERE USER_ID = "ALDIGIN USER ID" AND PASSWORD = "ALDIGIN PASSWORD";

//user_id'yi bir structure'a al;

login olunurken user datasini al: SELECT LOCAL_NUMBER, IS_ADM FROM USERS WHERE USER_ID = "STRUCT.USER_ID";

//is_adm'yi ve local_number'i alarak, bu adam hangi lokasyon'da ve admin mi degil mi ogren, bunlari da structure'a isle
(requirementlarda admin ve olmayan kisilerin farkli ozelliklerle karsilanacagini yazdik, o yuzden gerekli bunlar)

Bu SQL ile normal adamin bagli oldugu agent'in sensorindex'ini ve agent ismini alarak, agent ismi GUI'de bastirip,
index ile de agent'a bagli sensorlere ulasabiliriz, SENSOR_INDEX_NUM'i da structure'a ekle ki sonra tekrar query gerekmesin:
SELECT AGENT_NAME, SENSOR_INDEX_NUMBER FROM AGENT WHERE AGENT_LOCATION = STRUCT.LOCAL_NUMBER;

Bagli olunan agent alindiktan sonra sensor datasini almak:    
SELECT * FROM SENSORS WHERE SENSOR_INDEX = STRUCTURE.SENSOR_INDEX_NUMBER; 

LOG'a entry icin, date default olarak geliyor:
INSERT INTO LOG (SENSOR_INDEX_NUMBER, SENSOR_ID, VALUE, LOCATION, IS_EMERGENCY) 
VALUES('STRUCTURE.SENSOR_INDEX_NUMBER', 'ENTRY ISTENEN SENSOR_ID', 'OKUNAN VALUE', STRUCT.LOCAL_NUMBER);

