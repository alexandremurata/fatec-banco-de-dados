package br.gov.sp.fatec.quantogastarestfull.controller;

import br.gov.sp.fatec.quantogastarestfull.model.Eletrodomestico;
import br.gov.sp.fatec.quantogastarestfull.model.Usuario;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class MainController {

	private Usuario usuario;

	@RequestMapping(value="/find/{nome}", method = RequestMethod.GET)
	public List<Eletrodomestico> pesquisarEletrodomestico(@PathVariable("nome") final String nome) {
		System.out.println("Chegou aqui");
		return null;
	}
}
