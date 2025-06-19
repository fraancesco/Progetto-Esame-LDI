# Struttura dell'Applicazione per la Gestione del Catalogo di Videogiochi

## 1. **File di Dati**
   - `videogiochi.bin`: File binario contenente i record dei videogiochi, ognuno con titolo, editore, sviluppatore, descrizione, anno di pubblicazione e generi.
   - `recensioni.bin`: File binario contenente le recensioni associate ai videogiochi, con giudizio (0-5), descrizione opzionale e riferimento al videogioco tramite ID.

## 2. Strutture Principali

### Struttura Videogioco
- **Descrizione**: Rappresenta un videogioco con tutti i suoi attributi. Ogni videogioco ha un ID univoco per essere referenziato nelle recensioni e nelle vendite.
- **Attributi**:
  - `titolo` (string): Il nome del videogioco.
  - `editore` (string): L'editore del videogioco.
  - `sviluppatore` (string): Lo sviluppatore del videogioco.
  - `descrizione` (string): Una breve descrizione del gioco.
  - `anno_pubblicazione` (int): L'anno di pubblicazione.
  - `generi` (lista di string): Uno o più generi associati al videogioco.
  - `numero_copie_vendute` (int): Contatore delle copie vendute.
  - `id_videogioco` (int): Identificativo univoco del videogioco.

### **Struttura `Recensione`**
- **Descrizione**: Rappresenta una recensione lasciata da un utente per un videogioco. Include un giudizio obbligatorio e una descrizione opzionale.
- **Attributi**:
  - `id_videogioco` (int): ID del videogioco recensito.
  - `giudizio` (int): Valutazione da 0 a 5.
  - `descrizione` (string, opzionale): Commento testuale della recensione.
## 3. **Interfacce Utente**

### **Menu Principale**
- **Opzioni**:
  1. **Admin**:
  2. **Utente**:
  3. **Esci**

### **Menu Amministratore**
- **Descrizione**: Fornisce all'amministratore tutte le funzionalità di gestione del catalogo, delle recensioni e delle statistiche.
- **Opzioni**:
  1. **Gestione Videogiochi**:
    Visualizzazione di tutti i videogiochi per poi:
     - Aggiungere un nuovo videogioco al catalogo.
     - Modificare i dati di un videogioco esistente.
     - Cancellare un videogioco dal catalogo.
  2. **Gestione Recensioni**:
     - Visualizza tutte le recensioni per un videogioco specifico.
  3. **Visualizzazione Videogiochi**:
     - Visualizza i videogiochi ordinati per giudizio medio o per numero di vendite.
     - Visualizzazione statistiche come media delle recensioni e il numero di copie vendute per un videogioco.
  4. **Torna al menu principale**

### **Menu Visitatore**
- **Descrizione**: Permette ai visitatori di cercare videogiochi, visualizzare dettagli, aggiungere recensioni e simulare acquisti.
- **Opzioni**:
  1. **Ricerca Videogiochi**:
     - Cerca videogiochi per titolo, sviluppatore, editore, genere o anno, con supporto per sottostringhe.
  2. **Visualizza Videogioco**:
     - Mostra tutte le informazioni di un videogioco, incluse le recensioni.
     - Visualizza i videogiochi ordinati per giudizio medio o per numero di vendite.
  3. **Aggiungi Recensione**:
     - Permette di lasciare una recensione per un videogioco, con giudizio e commento opzionale.
  4. **Acquista Videogioco**:
     - Simula l'acquisto di un videogioco, incrementando il contatore delle vendite.
  5. **Torna al menu principale**

## 3. **Modularità**

  ### **1. Main**
  - **Descrizione**: Avvio dell'applicazione.

  ### **2. Modulo Catalogo**
  - `catalogo.c`: Gestisce le operazioni CRUD (Creazione, Lettura, Aggiornamento, Cancellazione) sui videogiochi. Si occupa  della logica di business relativa ai dati dei giochi.

  ### **3. Modulo Recensioni**
  - `recensioni.c`: Gestisce l'aggiunta, la modifica e la visualizzazione delle recensioni. Calcola le statistiche come le medie dei  voti.
  
  ### **4. Modulo Ricerca**
  - `ricerca.c`: Implementa gli algoritmi di ricerca (per titolo, genere, anno, ecc.) con supporto a sottostringhe e matching parziale. Offre funzioni riutilizzabili per tutti i tipi di ricerca.
  
  ### **5. Modulo File Manager**
  - `file_manager.c`: Centralizza tutte le operazioni di I/  O su file binari. Fornisce funzioni generiche per leggere e scrivere record, gestendo errori e accessi concorrenti.
  
  ### **6. Modulo Interfaccia Utente**
  - `ui.c`: Contiene tutte le funzioni per l'interazione con l'utente: menu, form di input, visualizzazione dei risultati e gestione  degli errori visuali.

  ### **7. Modulo Statistiche**
  - `stats.c`: Calcola metriche avanzate come medie dei voti, trend di vendite e genera report ordinati.

  Ogni operazione effettuata sara' salvata in un file di log