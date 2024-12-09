package main

import (
	"atividade/functions"
	"encoding/json"
	"fmt"
	"net/http"
	"os"
)

type Request struct {
	Choice int `json:"choice"`
	Input  struct {
		N int `json:"n"`
		A int `json:"a"`
		B int `json:"b"`
	} `json:"input"`
}

func handler(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Access-Control-Allow-Origin", "*")
	w.Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS, PUT, DELETE")
	w.Header().Set("Access-Control-Allow-Headers", "Content-Type, Authorization")

	if r.Method == "OPTIONS" {
		return
	}

	var req Request
	if err := json.NewDecoder(r.Body).Decode(&req); err != nil {
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}

	var result string
	switch req.Choice {
	case 1:
		result = fmt.Sprintf("Fatorial de %d é %d", req.Input.N, functions.Factorial(req.Input.N))
	case 2:
		result = fmt.Sprintf("Fibonacci de %d é %d", req.Input.N, functions.Fibonacci(req.Input.N))
	case 3:
		result = fmt.Sprintf("Números naturais de 1 a %d: ", req.Input.N)
		functions.PrintNaturals(req.Input.N)
	case 4:
		result = fmt.Sprintf("Somatório de 1 a %d é %d", req.Input.N, functions.SumNaturals(req.Input.N))
	case 5:
		result = fmt.Sprintf("MDC de %d e %d é %d", req.Input.A, req.Input.B, functions.Gcd(req.Input.A, req.Input.B))
	case 6:
		result = fmt.Sprintf("MMC de %d e %d é %d", req.Input.A, req.Input.B, functions.Lcm(req.Input.A, req.Input.B))
	case 7:
		result = fmt.Sprintf("Tabela Z_%d para adição modular:\n", req.Input.N)
		functions.AdditionTable(req.Input.N)
	case 8:
		result = fmt.Sprintf("Tabela Z_%d para multiplicação modular:\n", req.Input.N)
		functions.MultiplicationTable(req.Input.N)
	case 9:
		result = "Saindo..."
	default:
		result = "Opção inválida!"
	}

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(map[string]string{"result": result})
}

func main() {
	http.HandleFunc("/", handler)
	port := os.Getenv("PORT")
	if port == "" {
		port = "8080"
	}
	fmt.Printf("Listening on port %s...\n", port)
	http.ListenAndServe(":"+port, nil)
}
