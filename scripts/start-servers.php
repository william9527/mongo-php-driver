<?php
require __DIR__ . "/" . "../tests/utils/orchestration.php";


$host = "http://192.168.112.10:8889";
if ($_ENV && isset($_ENV["ORCHESTRATION"])) {
    $host = $_ENV["ORCHESTRATION"];
}

$orch = new Mongo\Orchestration($host);

$orch->stopAll();

$standalone = $orch->startStandalone();
printf("Standalone server running on: %s\n", $standalone);
