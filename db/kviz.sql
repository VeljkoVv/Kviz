PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "Kviz" (
	"id"	INTEGER NOT NULL,
	"naziv"	TEXT NOT NULL CHECK(length("naziv") <= 100),
	PRIMARY KEY("id")
);
INSERT INTO Kviz VALUES(1,'Geografija sveta');
INSERT INTO Kviz VALUES(2,'Istorija');
INSERT INTO Kviz VALUES(3,'Nauka');
INSERT INTO Kviz VALUES(4,'Programiranje C++');
INSERT INTO Kviz VALUES(5,'Sport');
INSERT INTO Kviz VALUES(6,'Srpska knjizevnost');
INSERT INTO Kviz VALUES(7,'Formula 1');
CREATE TABLE IF NOT EXISTS "Pitanja" (
	"id"	INTEGER NOT NULL,
	"kviz_id"	INTEGER NOT NULL,
	"tekst"	TEXT NOT NULL CHECK(length("tekst") <= 300) UNIQUE,
	"odgovor1"	TEXT NOT NULL CHECK(length("odgovor1") <= 100),
	"odgovor2"	TEXT NOT NULL CHECK(length("odgovor2") <= 100),
	"odgovor3"	TEXT NOT NULL CHECK(length("odgovor3") <= 100),
	"odgovor4"	TEXT NOT NULL CHECK(length("odgovor4") <= 100),
	"tacan_odgovor"	INTEGER NOT NULL CHECK("tacan_odgovor" BETWEEN 1 AND 4),
	PRIMARY KEY("id"),
	FOREIGN KEY("kviz_id") REFERENCES "Kviz"("id")
);
INSERT INTO Pitanja VALUES(1,1,'Koji je glavni grad Australije?','Sidnej','Melburn','Kanbera','Pert',3);
INSERT INTO Pitanja VALUES(2,1,'Koja je najduza reka na svetu?','Nil','Amazon','Jangce','Misisipi',1);
INSERT INTO Pitanja VALUES(3,1,'Koji je najveci okean na Zemlji?','Atlantski','Indijski','Severni ledeni','Tihi',4);
INSERT INTO Pitanja VALUES(4,1,'Na kom kontinentu se nalazi Egipat?','Azija','Afrika','Evropa','Juzna Amerika',2);
INSERT INTO Pitanja VALUES(5,1,'Koja je najvisa planina na svetu?','K2','Mont Blan','Mont Everest','Kilimandzaro',3);
INSERT INTO Pitanja VALUES(6,1,'Koji je glavni grad Kanade?','Toronto','Otava','Vankuver','Montreal',2);
INSERT INTO Pitanja VALUES(7,1,'Koja drzava ima najvecu povrsinu?','Kina','SAD','Kanada','Rusija',4);
INSERT INTO Pitanja VALUES(8,1,'Kroz koliko drzava protice Dunav?','6','8','10','12',3);
INSERT INTO Pitanja VALUES(9,1,'Koja je najveca pustinja u Africi?','Sahara','Kalahari','Namib','Gobi',1);
INSERT INTO Pitanja VALUES(10,1,'Koji je glavni grad Japana?','Kjoto','Osaka','Tokio','Jokohama',3);
INSERT INTO Pitanja VALUES(11,2,'Koje godine je poceo Prvi svetski rat?','1912','1914','1918','1939',2);
INSERT INTO Pitanja VALUES(12,2,'Koje godine je zavrsen Drugi svetski rat?','1943','1944','1945','1946',3);
INSERT INTO Pitanja VALUES(13,2,'Ko je predvodio Prvi srpski ustanak?','Milos Obrenovic','Karadjordje','Hajduk Veljko','Knez Lazar',2);
INSERT INTO Pitanja VALUES(14,2,'Koje godine se odigrala Kosovska bitka?','1371','1389','1453','1459',2);
INSERT INTO Pitanja VALUES(15,2,'Ko je bio prvi predsednik SAD?','Abraham Linkoln','Tomas Dzeferson','Dzordz Vasington','Dzon Adams',3);
INSERT INTO Pitanja VALUES(16,2,'Koje godine je pao Berlinski zid?','1987','1989','1991','1993',2);
INSERT INTO Pitanja VALUES(17,2,'Koja civilizacija je izgradila Macu Pikcu?','Maje','Asteci','Inke','Olmeci',3);
INSERT INTO Pitanja VALUES(18,2,'Koje godine je Kolumbo stigao do Amerike?','1492','1498','1453','1519',1);
INSERT INTO Pitanja VALUES(19,2,'Ko je bio prvi srpski arhiepiskop?','Sveti Sava','Stefan Nemanja','Stefan Prvovencani','Car Dusan',1);
INSERT INTO Pitanja VALUES(20,2,'Koje godine je Srbija stekla nezavisnost na Berlinskom kongresu?','1804','1830','1918','1878',4);
INSERT INTO Pitanja VALUES(21,3,'Koja je hemijska oznaka za zlato?','Ag','Au','Zn','Fe',2);
INSERT INTO Pitanja VALUES(22,3,'Koja planeta je najbliza Suncu?','Venera','Mars','Merkur','Zemlja',3);
INSERT INTO Pitanja VALUES(23,3,'Na kojoj temperaturi voda kljuca na nivou mora?','90 C','100 C','110 C','120 C',2);
INSERT INTO Pitanja VALUES(24,3,'Koliko hromozoma ima covek?','23','44','46','48',3);
INSERT INTO Pitanja VALUES(25,3,'Koja je najveca planeta Suncevog sistema?','Saturn','Jupiter','Neptun','Uran',2);
INSERT INTO Pitanja VALUES(26,3,'Ko je formulisao teoriju relativnosti?','Isak Njutn','Nikola Tesla','Albert Ajnstajn','Nils Bor',3);
INSERT INTO Pitanja VALUES(27,3,'Koji gas biljke upijaju tokom fotosinteze?','Kiseonik','Azot','Ugljen-dioksid','Vodonik',3);
INSERT INTO Pitanja VALUES(28,3,'Kolika je priblizno brzina svetlosti?','300.000 km/s','150.000 km/s','30.000 km/s','1.000.000 km/s',1);
INSERT INTO Pitanja VALUES(29,3,'Koji organ proizvodi insulin?','Jetra','Gusteraca','Bubrezi','Zeludac',2);
INSERT INTO Pitanja VALUES(30,3,'Koja je jedinica za elektricni otpor?','Volt','Amper','Vat','Om',4);
INSERT INTO Pitanja VALUES(31,4,'Koji operator se koristi za pristup clanu objekta preko pokazivaca?','.','->','::','&',2);
INSERT INTO Pitanja VALUES(32,4,'Koja STL kolekcija cuva jedinstvene, sortirane elemente?','std::vector','std::list','std::set','std::deque',3);
INSERT INTO Pitanja VALUES(33,4,'Koja kljucna rec sprecava izmenu vrednosti promenljive?','static','const','volatile','mutable',2);
INSERT INTO Pitanja VALUES(34,4,'Koliko vraca sizeof(char)?','1','2','4','8',1);
INSERT INTO Pitanja VALUES(35,4,'Koji header je potreban za koriscenje std::cout?','<string>','<vector>','<cstdio>','<iostream>',4);
INSERT INTO Pitanja VALUES(36,4,'Kako se zove funkcija koja se poziva pri unistavanju objekta?','Konstruktor','Destruktor','Operator','Inicijalizator',2);
INSERT INTO Pitanja VALUES(37,4,'Koji pametni pokazivac ima jedinstveno vlasnistvo nad objektom?','std::shared_ptr','std::weak_ptr','std::unique_ptr','std::auto_ptr',3);
INSERT INTO Pitanja VALUES(38,4,'Koja kljucna rec omogucava polimorfizam u vreme izvrsavanja?','virtual','override','final','inline',1);
INSERT INTO Pitanja VALUES(39,4,'Koji je indeks prvog elementa niza u C++?','-1','0','1','Zavisi od kompajlera',2);
INSERT INTO Pitanja VALUES(40,4,'Koja metoda dodaje element na kraj std::vector?','insert','push_front','append','push_back',4);
INSERT INTO Pitanja VALUES(41,5,'Koliko igraca jednog fudbalskog tima je na terenu?','9','10','11','12',3);
INSERT INTO Pitanja VALUES(42,5,'Na kom turniru je Novak Djokovic osvojio svoj prvi grend slem?','Australijan open','Rolan Garos','Vimbldon','US open',1);
INSERT INTO Pitanja VALUES(43,5,'Koliko poena vredi sut iza linije 6.75 u kosarci?','1','2','3','4',3);
INSERT INTO Pitanja VALUES(44,5,'U kom gradu su odrzane Zimske olimpijske igre 1984. godine?','Beograd','Zagreb','Sarajevo','Ljubljana',3);
INSERT INTO Pitanja VALUES(45,5,'Koliko minuta traje regularni deo fudbalske utakmice?','80','90','100','120',2);
INSERT INTO Pitanja VALUES(46,5,'Koliko setova treba osvojiti za pobedu u muskom mecu na grend slemu?','2','3','4','5',2);
INSERT INTO Pitanja VALUES(47,5,'Koji sport se igra na Vimbldonu?','Golf','Kriket','Tenis','Ragbi',3);
INSERT INTO Pitanja VALUES(48,5,'Koliko igraca jednog odbojkaskog tima je na terenu?','5','6','7','8',2);
INSERT INTO Pitanja VALUES(49,5,'Na koliko godina se odrzavaju Letnje olimpijske igre?','2','3','4','5',3);
INSERT INTO Pitanja VALUES(50,5,'Koja sahovska figura se krece u obliku slova L?','Lovac','Skakac','Top','Kraljica',2);
INSERT INTO Pitanja VALUES(51,6,'Ko je napisao roman Na Drini cuprija?','Mesa Selimovic','Milos Crnjanski','Ivo Andric','Branko Copic',3);
INSERT INTO Pitanja VALUES(52,6,'Ko je reformisao srpsku azbuku?','Dositej Obradovic','Vuk Karadzic','Petar II Petrovic Njegos','Sveti Sava',2);
INSERT INTO Pitanja VALUES(53,6,'Koji pisac sa ovih prostora je dobio Nobelovu nagradu za knjizevnost?','Ivo Andric','Danilo Kis','Dobrica Cosic','Borislav Pekic',1);
INSERT INTO Pitanja VALUES(54,6,'Ko je autor Gorskog vijenca?','Petar II Petrovic Njegos','Branko Radicevic','Laza Kostic','Jovan Jovanovic Zmaj',1);
INSERT INTO Pitanja VALUES(55,6,'Ko je napisao roman Dervis i smrt?','Ivo Andric','Mesa Selimovic','Danilo Kis','Milorad Pavic',2);
INSERT INTO Pitanja VALUES(56,6,'Ko je autor Hazarskog recnika?','Borislav Pekic','Danilo Kis','Milos Crnjanski','Milorad Pavic',4);
INSERT INTO Pitanja VALUES(57,6,'Ko je napisao roman Seobe?','Milos Crnjanski','Ivo Andric','Dobrica Cosic','Branislav Nusic',1);
INSERT INTO Pitanja VALUES(58,6,'Ko je napisao komediju Gospodja ministarka?','Jovan Sterija Popovic','Branislav Nusic','Petar Kocic','Radoje Domanovic',2);
INSERT INTO Pitanja VALUES(59,6,'Ko je napisao pesmu Santa Maria della Salute?','Jovan Ducic','Aleksa Santic','Djura Jaksic','Laza Kostic',4);
INSERT INTO Pitanja VALUES(60,6,'Ko je napisao dramu Kostana?','Stevan Sremac','Janko Veselinovic','Borisav Stankovic','Radoje Domanovic',3);
INSERT INTO Pitanja VALUES(61,7,'Ko je najmladji sampion u istoriji F1?','Max Verstappen','Lewis Hamilton','Kimi Antonelli','Sebastian Vettel',3);
INSERT INTO Pitanja VALUES(62,7,'Koji tim ima najvise konstruktorskih titula u istoriji F1?','Ferrari','McLaren','Mercedes','Williams',1);
INSERT INTO Pitanja VALUES(63,7,'U kojoj zemlji se nalazi staza Silverstone?','Nemacka','Belgija','Italija','Velika Britanija',4);
INSERT INTO Pitanja VALUES(64,7,'Ko je poznat pod nadimkom "kralj kise"','Michael Schumacher','Ayrton Senna','Lewis Hamilton','Max Verstappen',2);
INSERT INTO Pitanja VALUES(65,7,'Na kojoj stazi se vozi VN Italije?','Monza','Imola','Monaco','Mugello',1);
INSERT INTO Pitanja VALUES(66,7,'Koliko titula svetskog prvaka ima Michael Schumacher','5','6','7','8',3);
INSERT INTO Pitanja VALUES(67,7,'Kako se zove zastitni deo iznad glave vozaca uveden 2018.?','Halo','Shield','Aeroscreen','Crown',1);
INSERT INTO Pitanja VALUES(68,7,'Koji tim je osvojio konstruktorsku titulu 2024. godine?','Red Bull','Ferrari','McLaren','Mercedes',3);
INSERT INTO Pitanja VALUES(69,7,'Ko je najmladji pobednik trke u istoriji F1?','Lewis Hamilton','Max Verstapen','Kimi Antonelli','Sebastian Vettel',2);
INSERT INTO Pitanja VALUES(70,7,'Za koji tim je Senna debitovao u F1 1984. godine?','McLaren','Lotus','Williams','Toleman',4);
CREATE TABLE IF NOT EXISTS "Rang_lista" (
	"id"	INTEGER,
	"ime_igraca"	TEXT,
	"id_kviza"	INTEGER,
	"bodovi"	INTEGER,
	PRIMARY KEY("id"),
	FOREIGN KEY("id_kviza") REFERENCES "Kviz"("id")
);
INSERT INTO Rang_lista VALUES(1,'VeljkoV',5,10);
INSERT INTO Rang_lista VALUES(2,'vv',5,10);
INSERT INTO Rang_lista VALUES(3,'VeljkoV',6,9);
INSERT INTO Rang_lista VALUES(4,'Sara',6,9);
INSERT INTO Rang_lista VALUES(5,'Sara',1,8);
INSERT INTO Rang_lista VALUES(6,'VeljkoV',1,7);
INSERT INTO Rang_lista VALUES(7,'VeljkoV',7,10);
INSERT INTO Rang_lista VALUES(8,'VeljkoV',3,7);
INSERT INTO Rang_lista VALUES(9,'Sara',7,10);
INSERT INTO Rang_lista VALUES(10,'Ivan',7,8);
COMMIT;
