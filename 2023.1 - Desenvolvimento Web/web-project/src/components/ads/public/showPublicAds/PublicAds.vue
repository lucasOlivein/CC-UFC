<script>
export default {
    props: {
        'anuncios': Array,
        empty: Boolean
    }
}

</script>
<template>
    <div v-if="!empty">
        <div v-for="(anuncio, i) in anuncios" :key="i" class="anuncios">
            <div class="container w-75 position-relative float-start ms-4">
                <div class="row mb-5">

                    <div class="col-4 border" id="text">

                        <div class="container">
                            <div class="row">
                                <div class="col-9">
                                    <h5>{{ anuncio.tittle }}</h5>
                                </div>
                                <div class="col-3">R$: <strong>{{ anuncio.preco }}</strong> </div>
                            </div>

                            <div class="row">
                                <div class="col">
                                    <p><strong>Descrição:</strong></p>
                                </div>
                            </div>
                            <div class="row justify-content-center border" id="descriptionField">

                                <p>{{ anuncio.description }}</p>
                            </div>
                            <div class="row">
                                <div class="col">
                                    <!-- <p>Contato: <strong>{{ anuncio.user.data.attributes.contato }}</strong></p> -->
                                </div>
                            </div>
                        </div>

                    </div>



                    <div class="col-8 border">
                        <div :id="'slideAnuncio' + i" class="carousel slide" data-bs-ride="carousel">
                            <div class="carousel-inner">
                                <div v-for="(photo, j) in anuncio.photos">
                                    <div v-if="j == 0" class="carousel-item active c-item">
                                        <img :src="'http://localhost:1337' + photo.url"
                                            class="d-block img-fluid c-img" alt="...">
                                    </div>
                                    <div v-else class="carousel-item c-item">
                                        <img :src="'http://localhost:1337' + photo.url"
                                            class="d-block img-fluid c-img" alt="...">
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

                </div>

            </div>

        </div>
    </div>
    <div v-else>
        <h2>Não há anúncios</h2>
    </div>
</template>


