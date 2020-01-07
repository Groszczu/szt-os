#pragma once
#include <unordered_map>
#include <string>
#include <cstdint>
#include "../../modules/ProcessManager/PCB.hpp"

class Shell;

class Interpreter {
	std::unordered_map<std::string, void(Interpreter::*)(PCB &)> insnMap;
	Shell *shell;

	void handleArithm(PCB &process, uint8_t(*op)(uint8_t, uint8_t));
	void insnADD(PCB &process); void insnSUB(PCB &process); void insnMUL(PCB &process);
	void insnDIV(PCB &process); void insnINC(PCB &process); void insnDSC(PCB &process);

	void handleJump(PCB &process, bool(*op)(uint8_t, uint8_t));
	void insnJP(PCB &process);
	void insnJZ(PCB &process); void insnJNZ(PCB &process);
	void insnJE(PCB &process); void insnJNE(PCB &process);
	void insnJA(PCB &process); void insnJAE(PCB &process);
	void insnJB(PCB &process); void insnJBE(PCB &process);

	void insnLO(PCB &process);

	void insnCP(PCB &process);

	void insnFO(PCB &process); void insnFC(PCB &process);
	void insnFR(PCB &process); void insnFW(PCB &process);

	std::string readNextParam(PCB &process);

	uint8_t getValue(PCB &process, std::string dest);
	void setValue(PCB &process, std::string dest, uint8_t value);

public:
	Interpreter(Shell *shell);
	~Interpreter();

	void handleInsn(PCB &process);
	std::string loadProgram(const std::string name);
};