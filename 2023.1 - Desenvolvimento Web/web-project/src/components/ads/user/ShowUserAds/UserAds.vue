<script>
import { Ads } from '../../../../stores/ads'
import { Auth } from '../../../../stores/user'
export default {
    props: {
        'anuncios': Object,
        'empty': Boolean
    },
    data() {
        return {
            ads: Ads(),
            user: Auth(),
            fields: {}
        }
    },
    methods: {
        updateButton(i) {
            this.anuncios[i].configOpt.optDiv = false
            this.anuncios[i].configOpt.editDiv = true
            this.anuncios[i].configOpt.disabled = false

            this.fields.tittle = this.anuncios[i].tittle
            this.fields.preco = this.anuncios[i].preco
            this.fields.description = this.anuncios[i].description
            this.fields.estado = this.anuncios[i].estado

            console.log(this.fields)
        },
        save(i) {
            this.anuncios[i].configOpt.optDiv = true
            this.anuncios[i].configOpt.editDiv = false
            this.anuncios[i].configOpt.disabled = true

            this.anuncios[i].tittle = this.fields.tittle
            this.anuncios[i].preco = this.fields.preco
            this.anuncios[i].description = this.fields.description
            this.anuncios[i].estado = this.fields.estado
            
            this.ads.updateAd(this.anuncios[i].id, this.user.token, this.fields)

        },
        saveAbord(i) {
            this.anuncios[i].configOpt.optDiv = true
            this.anuncios[i].configOpt.editDiv = false
            this.anuncios[i].configOpt.disabled = true


            
        },
        deleteButton(i) {
            this.anuncios[i].configOpt.optDiv = false
            this.anuncios[i].configOpt.deleteDiv = true

        },
        deleteAbort(i) {
            this.anuncios[i].configOpt.optDiv = true
            this.anuncios[i].configOpt.deleteDiv = false
        },

        async deleteAd(i) {
            const res = await this.ads.deleteAd(this.anuncios[i].id, this.user.token)
            console.log(res)
            if(res.status == 200){
                this.anuncios[i].show = false
            }else {
                
            }
        },

    }


}

</script>
<template>
    <div v-if="!empty">
        <div v-for="(anuncio, i) in anuncios" :key="i" class="anuncios">
            <div v-if="anuncio.show" class="container w-75 position-relative float-start ms-4">
                <div class="row mb-5">


                    <form class="col-6 border" :ref="'fields_' + i">
                        <div class="row justify-content-center mb-3">
                            <div class="col-7">
                                <div class="row">
                                    <div class="container">
                                        <div class="row">
                                            <h5>Título: </h5>
                                        </div>
                                        <div class="row">
                                            <input type="text" class="flex" :id="'titulo' + i" :value="anuncio.tittle"
                                                @input="fields.tittle = $event.target.value"
                                                :disabled="anuncio.configOpt.disabled" style="width: auto;">
                                        </div>
                                    </div>
                                </div>
                            </div>




                            <div class="col-3">
                                <div class="container">
                                    <h5>Preço:</h5>
                                    <div class="row">
                                        <input type="number" :id="'preco' + i" :value="anuncio.preco"
                                            @input="fields.preco = $event.target.value"
                                            :disabled="anuncio.configOpt.disabled">
                                    </div>
                                </div>
                            </div>
                        </div>



                        <div class="row justify-content-center">
                            <div class="container">
                                <h5>Descrição:</h5>
                                <div class="row mx-1">
                                    <textarea type="text" :id="'description' + i" style="width: 100%; height: 100%;"
                                        :value="anuncio.description" @input="fields.description = $event.target.value"
                                        :disabled="anuncio.configOpt.disabled"></textarea>
                                </div>
                            </div>

                        </div>

                        <div class="row mt-3">
                            <div class="col-3">
                                <h5>Estado:</h5>
                            </div>
                            <div class="col-6">
                                <select :id="'estadoField' + i" class="form-select mb-3"
                                    :disabled="anuncio.configOpt.disabled" placeholder="Estado"
                                    aria-label="Default select example" :value="anuncio.estado"
                                    @input="fields.estado = $event.target.value">
                                    <option value="Novo">Novo</option>
                                    <option value="Usado em estado novo">Usado em estado novo</option>
                                    <option value="Usado em boas condições">Usado em boas condições</option>
                                    <option value="Usado em condições razoáveis">Usado em condições razoaveis</option>
                                </select>
                            </div>
                        </div>
                    </form>



                    <div class="col-4 border">
                        <div :id="'slideAnuncio' + i" class="carousel slide" data-bs-ride="carousel">
                            <div class="carousel-inner">
                                <div v-for="(photo, j) in anuncio.photos">
                                    <div v-if="j == 0" class="carousel-item active c-item">
                                        <img :src="'http://localhost:1337' + photo.url" class="d-block img-fluid c-img"
                                            alt="...">
                                    </div>
                                    <div v-else class="carousel-item c-item">
                                        <img :src="'http://localhost:1337' + photo.url" class="d-block img-fluid c-img"
                                            alt="...">
                                    </div>
                                </div>

                            </div>

                            <button class="carousel-control-prev" type="button" :data-bs-target="'#slideAnuncio' + i"
                                data-bs-slide="prev">
                                <span class="carousel-control-prev-icon" aria-hidden="true"></span>
                                <span class="visually-hidden">Previous</span>
                            </button>
                            <button class="carousel-control-next" type="button" :data-bs-target="'#slideAnuncio' + i"
                                data-bs-slide="next">
                                <span class="carousel-control-next-icon" aria-hidden="true"></span>
                                <span class="visually-hidden">Next</span>
                            </button>
                        </div>
                    </div>


                    <div class="col-2 border" style="justify-content: center;">
                        <div v-if="anuncio.configOpt.optDiv">
                            <button class="btn btn-primary my-3 " @click.prevent="updateButton(i)">Editar</button>
                            <button class="btn btn-danger " @click.prevent="deleteButton(i)">Excluir</button>
                        </div>

                        <div v-if="anuncio.configOpt.editDiv">
                            <button class="btn btn-outline-success m-3" @click.prevent="save(i)">Salvar</button>
                            <button class="btn btn-primary" @click.prevent="saveAbord(i)">Abortar</button>
                        </div>

                        <div v-if="anuncio.configOpt.deleteDiv">
                            <button class="btn btn-danger m-3" @click.prevent="deleteAbort(i)">Abortar</button>
                            <button class="btn btn-danger m-3" @click.prevent="deleteAd(i)">Confirmar</button>
                        </div>

                    </div>

                </div>

            </div>

        </div>
    </div>
    <div v-else>
        <h2>Não há anúncios</h2>
    </div>
</template>


