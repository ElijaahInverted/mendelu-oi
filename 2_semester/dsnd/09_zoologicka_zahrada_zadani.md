# Projekt 1: Databázový model – Zoologická zahrada 🦁

Tento dokument slouží jako kompletní checklist a průvodce pro vypracování vašeho prvního projektu. Sdružuje obecná pravidla pro první projekt a konkrétní byznysové požadavky (podniková pravidla) pro scénář Zoo.

## 1. Základní organizační informace

- **Forma práce:** Práce ve dvojicích (v rámci jednoho cvičení).
- **Cíl projektu:** Vytvořit návrh datového modelu pomocí entitně relačního diagramu (ERD) na základě zadaného scénáře a tento model odprezentovat.
- **Nástroj pro modelování:** SQL Developer Data Modeler od Oraclu.
- **Termíny podle harmonogramu:**
  - **3. týden:** Samostatná práce na projektu, konzultace, převod do fyzického modelu.
  - **4. týden:** Prezentace prvního projektu na cvičení.
- **Deadline:** Všechny projekty (včetně případných oprav) musí být odevzdány nejpozději do 1. června.
- **Hodnocení:** Projekt se hodnotí podle 7 kritérií na škále do 100 bodů (viz tabulka níže). Pro uznání projektu je nutné získat alespoň 60 % (60 bodů). Za úspěšný projekt získáte až 10 bodů do celkového hodnocení předmětu.

## 2. Analýza zadání (Scénář „Zoologická zahrada“)

Na základě dokumentu je nutné navrhnout databázi, která nahradí papírovou evidenci. Níže jsou extrahované entity, atributy a vztahy (tzv. business rules), které musí váš model pokrýt:

### 🐾 Zvířata a jejich taxonomie
- **Biologická klasifikace:** Eviduje se říše, kmen, třída, řád, čeleď, rod a druh.
- **Jazykové mutace:** Názvy musí být minimálně česky, latinsky a anglicky (model by měl být připraven i na další jazyky).
- **Přirozené prostředí:**
  - Země přirozeného výskytu.
  - Preferovaný typ krajiny (poušť, savana, deštný prales atd.).
- **Konkrétní zvířata (Individua):**
  - Většina má vlastní jméno.
  - Rodiče (pouze pokud jsou rodiče z této zoo – pozn. pro model: půjde o sebereferenční vztah (rekurzivní vazbu) na entitu zvířete).
  - Datum a místo narození (volitelné – pouze pokud je informace známá).
  - Pohlaví.
  - Specifikace / textový popis zvířete.

### 📍 Lokace (Umístění zvířat)
- **Tematické bloky:** Sdružují zvířata z podobných oblastí nebo s podobnými nároky. Mají svůj specifický název.
- **Ohrady:** Všechna zvířata jsou umístěna v ohradách. Ohrady jsou rozmístěny do tematických bloků. Budovy obsahující terária a akvária jsou na úrovni ohrad (tzn. akvárium/terárium = ohrada).

### 🧑‍💼 Zaměstnanci a pracovní pozice
- **Osobní údaje:** Evidují se základní osobní údaje, potřebné kontakty a bankovní spojení.
- **Pracovní pozice:** Zaměstnanci mohou mít různé pozice. Jeden zaměstnanec může zastávat i více pracovních pozic současně.
- **Atributy k pozici:** Datum nástupu na pozici a datum ukončení působení na pozici.
- **Úvazek:** Celkový úvazek jednoho zaměstnance napříč pozicemi nesmí překročit 1,5násobek běžné pracovní doby (pozn. pro model: toto bude jedno z vašich integritních omezení / podnikových pravidel).

### 🧹 Ošetřovatelé a Krmení
- **Ošetřovatelé:** Jde o zaměstnance, kteří mají patřičné proškolení. Pouze ti se smí starat o zvířata.
- **Přiřazení k ohradám:** Ošetřovatel se stará vždy o konkrétní ohradu (nebo terária, akvária).
  - Jeden ošetřovatel může mít na starost jednu nebo více ohrad.
  - O jednu ohradu se může starat více ošetřovatelů (vztah M:N).
- **Deník krmení:** Je nutné znát:
  - Které zvíře bylo krmeno.
  - Čím bylo krmeno.
  - Kdy (datum a čas).
  - Kým (kterým ošetřovatelem) bylo krmeno.

### 👨‍👩‍👧‍👦 Návštěvnost
Systém musí sledovat denní návštěvnost.
- **Sledované údaje:**
  - Konkrétní den (datum).
  - Kategorie návštěvníka (děti do 6 let, studenti, dospělí, důchodci...).
  - Počet návštěvníků v dané kategorii v daný den.
  - Čas příchodu návštěvníků.
  - Délka času (jak dlouho v zoo strávili).

## 3. Požadavky na odevzdání (Dokumentace a Prezentace)

Kromě samotného naklikání modelu v Data Modeleru musíte vytvořit dokumentaci (odevzdává se do UIS) a projekt prezentovat na cvičení.

### A. Struktura dokumentace
Dokumentace musí jasně popisovat postup tvorby modelu a musí obsahovat následující části (vzor najdete v dokumentovém serveru v UIS):
1. **Úvod**
2. **Maticový diagram** (pro zobrazení základních vazeb mezi entitami).
3. **Vztahy popsané pomocí ERDish** (minimálně 5 důležitých vztahů rozepsaných obousměrně a česky/anglicky, např.: *"Každý OŠETŘOVATEL musí krmit jednoho nebo více ZVÍŘAT..."*).
4. **ER diagram** (vyexportovaný obrázek z nástroje).
5. **Integritní omezení / Podniková pravidla** (zde uvedete např. pravidlo o úvazku max. 1,5, omezení, že rodiče zvířete musí být ze stejné zoo apod.).
6. **Závěr a doporučení**.

*Pozor: Bude se kontrolovat gramatická správnost a jednotnost formátování (obrázky, fonty, barvy).*

### B. Prezentace
Proběhne na 4. cvičení.
- **Hodnotí se:** přesvědčivost argumentů, způsob prezentace, schopnost vystupovat jako tým a schopnost individuálně odpovídat na položené dotazy.

## 4. Hodnoticí kritéria pro 1. projekt (Maximum 100 bodů)

Abyste prošli, musíte nasbírat minimálně 60 bodů.

| Kategorie | Popis toho, co se hodnotí | Body |
| :--- | :--- | :--- |
| **ER-Model entity** | Model je jasně vysvětlen (v dok. i prez.). Entity jsou řádně popsány, názvy odpovídají jmenné konvenci. Správné rozdělení entit. | 20 |
| **ER-Model atributy** | Entity obsahují správné atributy dle jmenné konvence. Správně specifikována povinnost/volitelnost/unikátnost atributů. ERD je ve 3. normální formě (3NF) (případně odůvodněné nedodržení). | 20 |
| **ER-Model vztahy** | Relační vztahy mají odpovídající pojmenování, směr, volitelnost i kardinalitu (násobnost). | 25 |
| **ER-Model rozložení** | Pozice entit a vztahů je logická. Všechny požadavky ze zadání (Zoo) jsou zahrnuty do ERD nebo jsou obsaženy v podnikových pravidlech. | 10 |
| **Dokumentace** | Fonty, barvy a text jsou konzistentní. Obsahuje všechny povinné části (viz struktura výše). Kontroluje se i gramatika. | 5 |
| **Prezentace** | Týmový výstup, přesvědčivost, zvládnutí individuálních odpovědí. (Dejte si pozor na rady přiložené ve vašem doplňujícím dokumentu v UIS). | 20 |

---

### 💡 Tipy a doporučení z pravidel předmětu:
- **Využití AI:** Není zakázáno, ale ve fázi studia se výrazně nedoporučuje. Pokud nebudete schopni u prezentace své řešení vysvětlit (např. proč jste zvolili danou vazbu), nebude uznáno, a to i kdyby bylo dokonalé.
- **Nejasnosti v zadání:** Zadání (scénář) může obsahovat nevyřčené věci nebo nejasnosti (což imituje realitu). Doptejte se svého cvičícího! Průběžné konzultace jsou naprosto legální formou pomoci.
- **Vazby:** Pokud je v zadání množné číslo (např. jazyky, ošetřovatelé se starají o ohrady), znamená to téměř vždy rozpad na vazební tabulku a vztah M:N, případně 1:N v logickém modelu.
