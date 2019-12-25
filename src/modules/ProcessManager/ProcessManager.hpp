#pragma once
#include "ProcessControl.hpp"
#include <vector>
#include <memory>
#include <string>

class ProcessManager {
	std::vector<PCB> processList;
	std::vector<PCB> readyQueue;
public:
	void createProcess(std::string name, std::string fileName);
	int getNextPID();

	std::vector<PCB>& getReadyQueue();
	std::vector<PCB>& getProcessList();

	void showChosenProcess(const PCB& process);
	static void showProcessList(std::vector<PCB> list);
	static void showReadyQueue(std::vector<PCB> queue);

	void deleteProcessFromList(int pid);

	void addProcessToList(PCB process);
	void addProcessToQueue(PCB process);

	PCB& getProcessFromList(std::string processName);

	void changeStatusChosenProcess(int pid, PCBStatus sts);
	/*
	 * processList - vector wszystkich procesow: nowych, oczekuj�cych itd.
	 * readyQueue - vector procesow gotowych
	 *
	 * createProcess - metoda dodaj�ca proces do listy wszystkich proces�w
	 * getNextPID - metoda generuj�ca niepowtarzalny numer ID
	 *
	 * getReadyQueue - metoda zwracaj�ca referencj� do kolejki procesow gotowych
	 * getProcessList - metoda zwracaj�ca referencj� do kolejki wszystkich procesow
	 *
	 * showChosenProcess - metoda wy�wietlaj�ca proces o podanej nazwie
	 * showProcessList - metoda wyswietlajaca list� wszystkich proces�w
	 * showReadyQueue - metoda wyswietlaj�ca kolejk� procesow gotowych
	 * deleteProcessFromList - metoda usuwaj�ca proces o podanym ID
	 * addProcessToList - metoda dodaj�ca wybrany proces do listy
	 * getProcessFromList - metoda zwracaj�ca proces o podanej nazwie
	 * TO DO
	 * changeStatusChosenProcess - metoda zmieniaja status procesu wybranego z listy
	 */
};
