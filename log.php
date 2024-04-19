<?php
if(isset($_REQUEST['q'])){
    // Ottieni l'indirizzo IP del client
    $ip = $_SERVER['REMOTE_ADDR'];
    
    // Ottieni la data e l'ora correnti
    $date = date('Y-m-d H:i:s');
    
    // Apriamo il file in modalità append
    $file = fopen('/var/www/html/cattura/catturato.txt', 'a');
    
    // Scriviamo l'indirizzo IP, la data, e i dati ricevuti nel file, separati da virgole
    fwrite($file, $ip . ',' . $date . ',' . base64_decode($_REQUEST['q']) . "\n");
    
    // Chiudiamo il file
    fclose($file);
    
    // Restituiamo i dati ricevuti
    echo $_REQUEST['q'];
}
?>
